#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    printf("%.1f",((double)(num*0.9+num*0.8+num)/3.0));
    return 0;
}