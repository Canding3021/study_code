#include<stdio.h>
#include<math.h>
int isPrime(int x){
    if(x<2){
        return 0;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int num;
    scanf("%d",&num);
    if(isPrime(num)){
        printf("Yes");
    }
    else{
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                printf("%d",i);
                break;
            }
        }
    }
    return 0;
}