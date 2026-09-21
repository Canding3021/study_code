#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    int qian=num/1000;
    int num1=qian*10+bai;
    int num2=shi*10+ge;
    int an1=num1+num2;
    double an2=(double)num1/num2*1.0;
    printf("%d %.1f",an1,an2);
    return 0;
}
