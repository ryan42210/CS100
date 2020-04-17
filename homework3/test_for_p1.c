#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RES_SIZE 128
#define NAME_SIZE 64


struct data {
    char name[NAME_SIZE];
    float score;
};

typedef struct data Student;


//When str1 > str2, return 1; else return 0.
int compare (const char* str1, const char* str2){
    while(*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    if (*str1 > *str2) return 1;
    else return 0;
}

void string_sort(char* strings[], int size) {
    for (int i = 0; i < size; i++){
        for (int j = 1; j < size-i; j++){
            if (compare(strings[j-1],strings[j]) == 1) {
                char *temp = strings[j-1];
                strings[j-1] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

Student* new_student(const char* _name, float _score) {
    Student* ptr_to_nstu = (Student*)malloc(sizeof(Student));
    strcpy(ptr_to_nstu->name, _name);
    ptr_to_nstu->score = _score;
    return ptr_to_nstu;
}

int main(){
    char* str[] = {"Finish", "Dog", "Egg", "dog", "Eggplant", "Fish"};
    string_sort(str, 6);
    for (int i = 0; i < 6; i++)
        printf("%s\n", str[i]);
    Student* geziWang = new_student("Gezi Wang", 0.0);
    printf("%s %f\n", geziWang->name, geziWang->score);
    return 0;
}