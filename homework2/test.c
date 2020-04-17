#include<stdlib.h>
#include<stdio.h>

int diff(int lenA, int lenB, int *a, int *b) {
    int minDiff = 0;
    int outputPosition = 0;

    for (int i = 0; i < lenA - lenB + 1; i++) {
        int diffOfEverySet = 0;
        for (int j = 0; j < lenB; j++) {
            int diffOfEveryElement = 0;
            diffOfEveryElement = a[j + i] - b[j];
            diffOfEveryElement = abs(diffOfEveryElement);
            diffOfEverySet = diffOfEverySet + diffOfEveryElement;
        }
        if (i == 0) minDiff = diffOfEverySet;
        if (minDiff > diffOfEverySet) {
            minDiff = diffOfEverySet;
            outputPosition = i;
        }
    }
    return outputPosition;
}

int main(){
    int a[6] = {3,2,4,1,7,5};
    int b[3] = {2,3,5};

    int position = diff(6,3,a,b);
    printf("%d %d %d", a[position], a[position + 1],a[position + 2]);

    return 0;
}