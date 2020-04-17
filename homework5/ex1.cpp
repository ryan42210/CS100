#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

const int ERRORCODE = -1;

class DataAnalyser {
public:
    DataAnalyser() {};
    virtual ~DataAnalyser() {};
    /**
     * virtual function "calculate"
     * @param data: the data array need to be calculated
     * @param size: the length of the data
     * @return: the calculated result
     */
    virtual float calculate(float* data, size_t size) {
        std::cout << "ERROR: Try to access virtual function which is in base class" << std::endl;
        return ERRORCODE;
    };
};


// MaximumAnalyser
class MaximumAnalyser : public DataAnalyser {
// Your code here.
public:
    virtual float calculate(float* data, size_t size) {
        float max = data[0];
        for (int i = 0; i < size; i++) {
            if (data[i] > max)
                max = data[i];
        }
        return max;
    };
};

// MinimumAnalyser
class MinimumAnalyser : public DataAnalyser {
// Your code here.
public:
    virtual float calculate(float* data, size_t size) {
        float min = data[0];
        for (int i = 0; i < size; i++) {
            if (data[i] < min)
                min = data[i];
        }
        return min;
    };
};

// AverageAnalyser
class AverageAnalyser : public DataAnalyser {
// Your code here.
public:
    virtual float calculate(float* data, size_t size) {
        float sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        float avg = sum/size;
        return avg;
    };
};

// MedianAnalyser
class MedianAnalyser : public DataAnalyser {
// Your code here.
public:
    virtual float calculate(float* data, size_t size) {
        std::sort(data, data + size);
        int judg = size % 2;
        int midIndex = 0;
        float median;
        if (judg == 0) {
            midIndex = size/2;
            median = (data[midIndex] + data[midIndex - 1]) / 2;
            return median;
        }
        else {
            midIndex = (size - 1) / 2;
            median = data[midIndex];
            return median;
        }
    };
};

// StdDevAnalyser
class StdDevAnalyser : public DataAnalyser {
// Your code here
public:
    virtual float calculate(float* data, size_t size) {
        float sum = 0;
        for (int i = 0; i < (int)size; i++) {
            sum += data[i];
        }
        float avg = sum/size;
        float dev = 0;
        for (int i = 0; i < size; i++) {
            dev += (data[i] - avg) * (data[i] - avg);
        }
        return sqrt(dev/size);
    };
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main() {
    /* Your can write your own main for testing */
    float arr[] = {0.3, -100, 1, 2, 5, 6, 9, 12};
    DataAnalyser* foo = new MedianAnalyser();
    std::cout << foo->calculate(arr, 8) << std::endl;
    delete foo;
    return 0;
}