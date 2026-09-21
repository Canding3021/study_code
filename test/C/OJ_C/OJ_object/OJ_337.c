#include<stdio.h>
int main(){
    double x;
    double pai=3.14;
    scanf("%lf",&x);
    double r=(x/pai)/2;
    double s=r*r*pai;
    printf("%.2f",s);
    return 0;
}