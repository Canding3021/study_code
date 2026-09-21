#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int z=a+b+c;
    double p=z/3.0;
    printf("%d\n",z);
    printf("%.1f\n",p);
    return 0;
}