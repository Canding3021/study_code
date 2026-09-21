#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int ge=a%10;
    int shi=(a/10)%10;
    double an=(double)shi/ge*1.0;
    printf("%.1f",an);
    return 0;
}