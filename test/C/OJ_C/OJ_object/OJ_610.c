#include<stdio.h>
int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    double money=(8.5*a+5.6*b+6.2*c);
    printf("%.1f",money);
    return 0;
}