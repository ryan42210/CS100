#include <stdio.h>

int main() {
    int n = 0;

    printf("Please type number of inputs: ");
    scanf("%d", &n);

    double newNumber;
    double Max = -10000.0, Min = 10000.0;

    for (int i = 1; i <= n; i++) {
        scanf("%f", &newNumber);

        if (newNumber >= Max) Max = newNumber;
        if (newNumber <= Min) Min = newNumber;
    }

    printf("Max value: %.1f\n", Max);
    printf("Min value: %.1f\n", Min);
    return 0;
}