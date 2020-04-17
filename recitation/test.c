#include<stdio.h>
#include<string.h>
#define TARGET "test"

int main(){
    char *originText = {"Here is the test sentence for this little task."};
    char target[] = {TARGET};
    char *copy = originText;

    int lenth_of_tar = strlen(target);
    for (int i = 0; i < strlen(originText)-lenth_of_tar;i++){
        do{
            /* */
        }while(/* */);
    };
    return 0;
}