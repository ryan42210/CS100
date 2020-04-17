#include<stdio.h>
#include<stdlib.h>

int main(){
    int *idList;
    float *scoreList;

    int inputID = 0;
    float inputScore = 0;

    int limitNum = 5;
    int counter = 0;

    idList = (int *)calloc(5,sizeof(int));
    scoreList = (float *)calloc(5,sizeof(float));

    printf("Please type scores to be calculated:\n");

    do{
        if (counter == limitNum) {
            limitNum = limitNum * 2;
            idList = (int *)realloc(idList,sizeof(int)*limitNum);
            scoreList = (float *)realloc(scoreList, sizeof(float)*limitNum);
            printf("(resize) from %d to %d\n",limitNum/2,limitNum);
            printf("(resize) from %d to %d\n",limitNum/2,limitNum);
        }
        scanf("%d %f",&inputID,&inputScore);

        if (inputID != -1) {
            idList[counter] = inputID;
            scoreList[counter] = inputScore;
            counter++;
        }

    } while (inputID != -1 );
    printf("---Result---\n");

    for (int i = 0; i < counter; i++){
        for (int j = 1; j < counter-i; j++){
            if (scoreList [j-1] > scoreList[j]){
                float temp1 = scoreList[j];
                scoreList[j] = scoreList[j-1];
                scoreList[j-1] = temp1;

                int temp2 = idList[j];
                idList[j] = idList[j-1];
                idList[j-1] = temp2;
            } else if (scoreList[j-1] == scoreList[j] ) {
                if (idList[j-1] > idList[j]){
                    float temp1 = scoreList[j];
                    scoreList[j] = scoreList[j-1];
                    scoreList[j-1] = temp1;

                    int temp2 = idList[j];
                    idList[j] = idList[j-1];
                    idList[j-1] = temp2;
                }
            }
        }
    }
    for (int i = 0; i < counter; i++){
        printf("%d %.1f\n", idList[i],scoreList[i]);
    }
    free(idList);
    free(scoreList);
return 0;
}