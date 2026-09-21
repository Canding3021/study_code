//分糖果问题
#include<stdio.h>
#include<math.h>
int main(){
    int a;
    int b;
    int c;
    int d;
    int e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    int share=a/3;
    a=share;
    b+=share;
    e+=share;
    share=b/3;
    b=share;
    a+=share;
    c+=share;
    share=c/3;
    c=share;
    b+=share;
    d+=share;
    share=d/3;
    d=share;
    c+=share;
    e+=share;
    share=e/3;
    e=share;
    a+=share;
    d+=share;


    printf("%d %d %d %d %d",a,b,c,d,e);


    return 0;
}