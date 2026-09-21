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
    int isprime[100];
    int index=0;
    if(isPrime(num)==1){
        printf("%d",num);
        return 0;
    }
    for(int i=2;i<=num;i++){
        if(isPrime(i)){
            isprime[index++]=i;
        }
        
    }
                                                                    /*int l=0;
                                                                    while(1){
                                                                        for(int l=0;l<index;l++){
                                                                            if(num%isprime[l]==0){
                                                                                printf("%d\n",isprime[l]);
                                                                                num/=isprime[l];
                                                                            }
                                                                            if(isPrime(num)==1){
                                                                                printf("%d",num);
                                                                            }
                                                                            if(num)
                                                                            break;
                                                                        }
                                                                        
                                                                    }
                                                                    */
    for (int i = 0; i < index; i++) {
        while (num % isprime[i] == 0) {  
            printf("%d\n", isprime[i]);  
            num /= isprime[i];  
        }
        if (num == 1) {  
            break;  
        }
    }

    if (num > 1) {
        printf("%d\n", num);
    }

    return 0;
}