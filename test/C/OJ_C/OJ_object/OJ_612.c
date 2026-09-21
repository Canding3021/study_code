#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    printf("%d\n",num);
    printf("%d\n",(num+8));
    printf("%d\n",(num+8-2));
    printf("%.1f",(double)(num*3+8+8-2)/3.0);
    return 0;
}