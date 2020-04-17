#include<stdio.h>
#include<math.h>

int main(){
    int h12,h24,min;
    char x;
    double h_agl,m_agl,dgre1,dgre2;

    printf("What time is it? ");
    scanf("%d %c %d",&h24,&x,&min);
    
    h12 = h24 % 12;
    h_agl = (h12*30) + (min/2.0);
    m_agl = min * 6;
    dgre1 = h_agl - m_agl;
    dgre1 = fabs(dgre1);
    if(dgre1 > 180) dgre2 = 360.0 - dgre1;
    else dgre2 = dgre1;

    printf("The angle between the hands is %.1f degrees.\n",dgre2);
    
    return 0;
}