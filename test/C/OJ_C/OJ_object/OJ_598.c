#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    double an=(double)c-(a+b)*0.9;
    printf("%.1f",an);
    return 0;
}