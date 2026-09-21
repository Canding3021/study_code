#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if(a<=10){
        printf("2.50");
    }
    else if(a>10){
        double x=a-10;
        printf("%.2lf",(2.50+x*1.50));
    }
    return 0;
}