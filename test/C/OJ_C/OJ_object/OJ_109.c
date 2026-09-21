//加密四位数
#include<stdio.h>
#include<math.h>
int main(){ 
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    int qian=num/1000;


    //变量不能重复定义！！！以下无需再加int。
    ge=(ge+5)%10;
    shi=(shi+5)%10;
    bai=(bai+5)%10;
    qian=(qian+5)%10;
    int an=ge*1000+shi*100+bai*10+qian;
    printf("%d\n",an);
    return 0;
}