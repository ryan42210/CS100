/*Calculating 5000 digits of pi*/
#include <stdio.h>
#include <math.h>

int main(){
    int a[16667];
    int pred = 0;
    int nines = 0;
    for (int j=0; j<16667; j++)
        a[j] = 2;                   //start with 2s
    
    for (int j=0; j<5000; j++){
        int q = 0;
        int i;
        
        /*backwards*/
        for (i = 16667;i>0; i--){
            int x;
            x = 10*a[i-1] + q*i;
            a[i-1] = x % (2*i-1);
            q = x / (2*i-1);
        }

        a[0] = q % 10;
        q = q / 10;
        
            /*print the digit*/
        
        if (j == 2)
            printf(".");        //print the '.' after the first digit
        
        if (q == 9){
            nines = nines + 1;
        }else if (q == 10){
            printf("%d",pred + 1);
            for(int k=0; k < nines; k++)
                printf("0");
            pred = 0;
            nines = 0;
        }else{
            if(j != 0){         //remove the '0' before 31414596....
                printf("%d",pred);
            }
            pred = q;
            if (nines != 0)
                for (int p=0; p < nines; p++)
                    printf("9");
                nines = 0;
        }    
           
    }
    printf("%d\n",pred);        //print the last digit

    return 0;
}