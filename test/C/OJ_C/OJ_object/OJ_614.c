#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i=100;i>0;i/=10){
        int answer=0;
        if(i!=10){
            answer+=(num/i);
            num%=i;
        }
        printf("%d",answer);
    }


    return 0;
}


//问题太简单，不需要循环
