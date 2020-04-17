#include <stdio.h>
#include <stdlib.h>

int main() {
    float *scoreList;
    float inputNumber = 0;
    int counter = 0;
    int limitNum = 5;

    scoreList = (float *)calloc(5,sizeof(float));

    printf("Please type scores to be calculated:\n");

    do {
        scanf("%f", &inputNumber);
        if (counter == limitNum) {
            limitNum = limitNum * 2;
            scoreList = (float *)realloc(scoreList, sizeof(float)*limitNum);
            printf("(resize) from %d to %d\n",limitNum/2,limitNum);
        }

        if (inputNumber!= -1) {
            scoreList[counter] = inputNumber;
            counter++;
        }

    } while (inputNumber != -1);

    float sum = 0;
    for (int i = 0; i < counter; i++) {
        sum = sum + scoreList[i];
    }
    printf("Average score: %.2f",sum/(counter));

    free(scoreList);
return 0;
}