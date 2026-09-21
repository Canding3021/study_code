#include<stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int b;
    b=x*y;
    int a;
    a=x%y;
    while(a!=0){
        x=y;
        y=a;
        a=x%y;
    }
    printf("%d",(b/y));
    return 0;
}