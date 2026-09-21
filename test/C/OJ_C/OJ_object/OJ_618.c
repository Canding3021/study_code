#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    int qian=num/1000;
    int day1=qian*10+bai;
    int day2=shi*10+ge;
    double an=(num+day1+day2)/3.0;
    printf("%.2lf",an);
    return 0;
}