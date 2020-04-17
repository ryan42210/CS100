#include "FilteredImage.hpp"
#include <iostream>

/**
 * Implementation of `FilteredImage::FilteredImage( Image & img )`
 * This is a constructor of class FilteredImage, which is defined in
 * `FilteredImage.hpp` You should set the member variable `_img` as given
 * parameter `img`
 * @param img: The image that will be filtered
 */
FilteredImage::FilteredImage(Image& img):_img(img) {}

/**
 * Implementation of `Image & FilteredImage::get( int type )`
 * This is a member function of class FilteredImage, which is defined in
 * `FilteredImage.hpp` You should refer to the documentation, finish 4 types of
 * applications Hint: The following 4 cases should be very similar.
 * @param type: The type of Kernel
 */
Image& FilteredImage::get(int type) {
    if (_filteredImages[type] != nullptr) {
        Image& result = *_filteredImages[type];
        return result;
    }
    _filteredImages[type] = std::make_shared<Image>(_img.rows(), _img.cols());
    switch (type) {
        case BLUR: {
            Kernel K_blur(5,5);
            K_blur << (2.0f/159.0f),(4.0f/159.0f),(5.0f/159.0f),(4.0f/159.0f),(2.0f/159.0f),
                    (4.0f/159.0f),(9.0f/159.0f),(12.0f/159.0f),(9.0f/159.0f),(4.0f/159.0f),
                    (5.0f/159.0f),(12.0f/159.0f),(15.0f/159.0f),(12.0f/159.0f),(5.0f/159.0f),
                    (4.0f/159.0f),(9.0f/159.0f),(12.0f/159.0f),(9.0f/159.0f),(4.0f/159.0f),
                    (2.0f/159.0f),(4.0f/159.0f),(5.0f/159.0f),(4.0f/159.0f),(2.0f/159.0f);
            applyKernel(_img, *_filteredImages[BLUR], K_blur);
            return *_filteredImages[BLUR];
        }
        case DER_X: {
            Kernel K_der_x(3,3);
            K_der_x << -1.0f, 0.0f, 1.0f,
                    -2.0f, 0.0f, 2.0f,
                    -1.0f, 0.0f, 1.0f;
            applyKernel(_img, *_filteredImages[DER_X], K_der_x);
            return *_filteredImages[DER_X];
        }
        case DER_Y: {
            Kernel K_der_y(3,3);
            K_der_y << -1.0f, -2.0f, -1.0f,
                    0.0f, 0.0f, 0.0f,
                    1.0f, 2.0f, 1.0f;
            applyKernel(_img, *_filteredImages[DER_Y], K_der_y);
            return *_filteredImages[DER_Y];
        }
        case DER_MAG: {
            Image tempX(_img.rows(), _img.cols());
            Image tempY(_img.rows(), _img.cols());
            Kernel K_der_x(3,3);
            K_der_x << -1.0f, 0.0f, 1.0f,
                    -2.0f, 0.0f, 2.0f,
                    -1.0f, 0.0f, 1.0f;
            Kernel K_der_y(3,3);
            K_der_y << -1.0f, -2.0f, -1.0f,
                    0.0f, 0.0f, 0.0f,
                    1.0f, 2.0f, 1.0f;
            applyKernel(_img, tempX, K_der_x);
            applyKernel(_img, tempY, K_der_y);
            for (int i = 0; i < _img.rows(); i++) {
                for (int j = 0; j < _img.cols(); j++) {
                    (*_filteredImages[DER_MAG])(i,j) 
                        = sqrt(tempX(i,j)*tempX(i,j) + tempY(i,j)*tempY(i,j));
                }
            }
            return *_filteredImages[DER_MAG];
        }
        default: { std::cout << "Error: unrecognized kernel option\n"; }
    }
    return _img;
}

/**
 * Implementation of `void FilteredImage::applyKernel( Image & input, Image &
 * output, Kernel & K )` This is a member function of class FilteredImage, which
 * is defined in `FilteredImage.hpp` You should do convolution operation for the
 * input image That is, OUTPUT = INPUT * KERNEL, where `*` is the convolution
 * operator
 * @param input: The input image
 * @param output: The output image
 * @param kernel: The convolution kernel
 */
void FilteredImage::applyKernel(Image& input, Image& output, Kernel& K) {
    int height = K.rows();
    int width = K.cols();
    for (int i = 0; i < input.rows(); i++) {
        for (int j = 0; j < input.cols(); j++) {
            output(i + (height-1)/2,j + (width-1)/2) = (K*input.block(height,width,i,j)).sum();
        }
    }
    output.leftCols((width-1)/2).setZero();
    output.rightCols((width-1)/2).setZero();
    output.topRows((height-1)/2).setZero();
    output.bottomRows((height-1)/2).setZero();
}