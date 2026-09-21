#include<stdio.h>
int max(int x,int y){
    return (x>y)?x:y;
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b && a>c){
        printf("%d\r",a);
    }
    else if(b>a && b>c){
        printf("%d\r",b);
    }
    else if(c>a && c>b){
        printf("%d\r",c);
    }



    return 0;
}