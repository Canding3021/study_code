#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int day=0;
    while(1){
        if(c-a>0){
            c=c-a+b;
            day++;
        }
        else{
            day++;
            printf("%d",day);
            break;
        }
    }
    return 0;
}