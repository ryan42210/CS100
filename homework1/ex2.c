#include <math.h>
#include <stdio.h>

float fun1(float a, float b, float c) {
    float max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    return max;
}

float fun2(float a, float b, float c) {
    float min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int main() {
    float x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;

    printf("Input vertex 1: ");
    scanf("%f %f", &x1, &y1);

    printf("Input vertex 2: ");
    scanf("%f %f", &x2, &y2);

    printf("Input vertex 3: ");
    scanf("%f %f", &x3, &y3);

    float centx, centy;
    centx = (x1 + x2 + x3) / 3.0;
    centy = (y1 + y2 + y3) / 3.0;
    printf("The center of the triangle is: %.1f %.1f\n", centx, centy);

    float d1, d2, d3;
    d1 = powf(centx - x1, 2) + powf(centy - y1, 2);
    d2 = powf(centx - x2, 2) + powf(centy - y2, 2);
    d3 = powf(centx - x3, 2) + powf(centy - y3, 2);

    float dct1, dct2, dct3;
    dct1 = sqrtf(d1);
    dct2 = sqrtf(d2);
    dct3 = sqrtf(d3);

    float dMax, dMin;

    dMax = fun1(dct1, dct2, dct3);
    dMin = fun2(dct1, dct2, dct3);
    printf("The maximum distance between center and vertices: %.2f\n", dMax);
    printf("The minimum distance between center and vertices: %.2f", dMin);

    return 0;
}