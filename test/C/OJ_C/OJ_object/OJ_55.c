#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int sum=0;
    for(int i=0;i<num;i++){
        if(i%3==2 && i%5==3 && i%7==2){
            sum++;
        }
    }
    printf("%d",sum);

    return 0;
}