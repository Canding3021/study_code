#include<stdio.h>
#include<math.h>
int main(){ 
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    double ans=(double)(bai+shi)/(shi+ge);
    printf("%.2f",ans);


    return 0;
}