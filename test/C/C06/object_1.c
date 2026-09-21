#include<stdio.h>
int main(){
    double x,y;
    printf("enter the x:");
    scanf("%lf",&x);
    if( (-5.0<=x) && (x!=2.0) && (x<0.0)){
        y=1.0/(x+2.0);
    }
    else if ((x<5.0)&&(x>=0.0)){
        y=1.0/(x+5.0);
    }
    else if ((5.0<=x)&&(x<10.0)){
        y=1.0/(x+12.0);
    }else   y=0;
    printf("x= %lf \ny= %lf \n",x,y);
}