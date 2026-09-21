#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    int qian=num/1000;
    int an=ge+shi+bai+qian;
    printf("%d",an);






    return 0;
}