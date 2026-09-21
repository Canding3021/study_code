#include<stdio.h>
long long jc(int a){
    long long res=1;
    for(int i=1;i<=a;i++){
        res*=i;
    }
    return res;
}
int main(){
    int num;
    scanf("%d",&num);
    long long sum=0;
    for(int i=1;i<=num;i++){
        sum+=jc(i);
    }
    printf("%lld",sum);
    return 0;
}