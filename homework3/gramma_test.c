#include<stdio.h>
#include<string.h>

int compare (const char* str1, const char* str2){
    while(*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return 1;
    else if (*str1 < *str2)
        return -1;
}

int main(){
    const char* str1 = "a";
    const char* str2 = "a";

    int i = compare(str1,str2);
    printf("%d\n",i);
    return 0;
}