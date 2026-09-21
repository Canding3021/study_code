#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    int qian=num/1000;
    int ans=shi*1000+ge*100+qian*10+bai*1;
    printf("%d",ans);
    return 0;
}