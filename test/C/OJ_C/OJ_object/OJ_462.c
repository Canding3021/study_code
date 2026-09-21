#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int h=0;
    int m=0;
    h=c-a;
    if(b>d){
        d+=60;
        m=d-b;
        h--;

    }
    else {
        m=d-b;
    }
    printf("%d %d",h,m);
    return 0;
}   