#include <stdio.h>

int main(){
    long long a = 0;
    long long b = 1;
    printf("The next number is %lld\n", a);
    printf("The next number is %lld\n", b);
    for( int i = 0; i < 44; i++ ) {
        a = a + b;
        printf( "The next number is %lld\n", a);
        b = b + a;
        printf( "The next number is %lld\n", b);
    }
    return 0;
}