//分跳绳
#include<stdio.h>
#include<math.h>
int main(){
    int m;
    int n;
    scanf("%d %d",&m,&n);
    int an1=m/n;
    int an2=m%n;
    printf("%d %d",an1,an2);
    return 0;
}