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
    int a;
    scanf("%d",&a);
    int x=1;
    int an=0;
    while(1){
        if(isPrime(x)==1 && x<a){
            printf("%d",x);
            printf("%d",x);
            printf("%d",x);
            printf("%d",x);
            printf("%d",x);
            printf("\n");
        }
        x++;
        if(x>a){
            break;
        }
    }
    return 0;
}