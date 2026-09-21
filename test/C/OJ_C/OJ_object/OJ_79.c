#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int a,b,c;
    int n=0;
    for(a=0;a<=num;a++){
        for(b=a+1;b<=num;b++){
            for(c=b+1;c<=num;c++){
                if(a!=b && b!=c && a!=c && a+b+c==num){
                    n++;
                }
            }
        }
    }
    printf("%d",n);
    return 0;
}