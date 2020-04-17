#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int *listA;
    int *listB;

    int inputA = 0;
    int inputB = 0;

    int limitNumA = 5;
    int counterA = 0;

    int limitNumB = 5;
    int counterB = 0;

    listA = (int *)calloc(5, sizeof(int));
    listB = (int *)calloc(5, sizeof(int));

    printf("Please input the set A:\n");

    do {
        if (counterA == limitNumA) {
            limitNumA = limitNumA * 2;
            listA = (int *)realloc(listA, sizeof(int) * limitNumA);
            printf("(resize) from %d to %d\n", limitNumA / 2, limitNumA);
        }
        scanf("%d", &inputA);

        if (inputA != -1) {
            listA[counterA] = inputA;
            counterA++;
        }
    } while (inputA != -1);

    printf("Please input the set B:\n");

    do {
        if (counterB == limitNumB) {
            limitNumB = limitNumB * 2;
            listB = (int *)realloc(listB, sizeof(int) * limitNumB);
            printf("(resize) from %d to %d\n", limitNumB / 2, limitNumB);
        }
        scanf("%d", &inputB);

        if (inputB != -1) {
            listB[counterB] = inputB;
            counterB++;
        }

    } while (inputB != -1);

    printf("---Result---\n");

    int position = diff(counterA, counterB, listA, listB);

    for (int i = 0; i < counterB;i++){
        printf("%d ", listA[position + i]);
    }
    free(listA);
    free(listB);

    return 0;
}