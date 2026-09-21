#include<stdio.h>
int max(int x,int y){
    return (x>y)?x:y;
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
     if(max(a+b,c)==a+b)
        printf("yes");
    else
        printf("no");
    return 0;
}