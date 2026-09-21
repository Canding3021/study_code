#include<stdio.h>
int pf(int x){
    return x*x;
}
int main(){
    int num;
    scanf("%d",&num);
    int sum=0;
    for(int i=1;i<=num;i++){
        sum+=pf(i);
    }
    printf("%d",sum);
    return 0;
}