#include<stdio.h>
#include<math.h>
int odd(int x){
    if(x%2==0){
        return 0;
    }
    return 1;
}
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
    int isprime[50];
    int n=2;
    int i=0;
    while(n<num){
        if(isPrime(n)==1){
            isprime[i]=n;
            i++;
        }
        n++;
    }
    if(odd(num)==1){
        num-=1;
    }
    int num1=0;
    for(num1=2;num1<=num;num1+=2){
        for(int i=0;i<100;i++){
            for(int l=i;l<100;l++){
                if(num1==isprime[i]+isprime[l]){
                    printf("%d=%d+%d\n", num1, isprime[i], isprime[l]);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}