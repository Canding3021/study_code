#include<stdio.h>
int main(){
    int a;
    int b;
    double pai=3.14;
    scanf("%d %d",&a,&b);
    double s=(b*b-a*a)*pai;
    printf("%.2f",s);
    return 0;
}