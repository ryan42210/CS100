#include<stdio.h>

int main(){
    
    char x;
    double var1;
    double var2;
    char op;
    double result;
    do {
        
        printf("Enter the arithmetic expression to be evaluated (e.g. 5 + 6):\n");
        scanf("%f %c %f", &var1, &op, &var2);
        getchar();
        if(op == '+'){
            result = var1 + var2;
        }else if(op == '-'){
            result = var1 - var2;
        }else if(op == '*'){
            result = var1 * var2;
        }else if (op == '/'){
            result = var1 / var2;
        }
        printf("%f\n", result);

        printf("Did you want to enter another expression? (Enter 'y' or 'n'): ");
        scanf("%c", &x);
    } while (x == 'y');
    
    return 0;
}