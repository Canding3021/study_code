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
    int a,b;
    scanf("%d %d",&a,&b);
    int x=2;
    int an=0;
    while(1){
        if(isPrime(x)==1 && x>a && x<b){
            an++;
        }
        x++;
        if(x>b){
            break;
        }
    }
    printf("%d",an);
    return 0;
}