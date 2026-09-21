//花园面积问题
#include<stdio.h>
int main(){
    int m;
    int n;
    int s;
    scanf("%d %d %d",&m,&n,&s);
    int kuan=s/n;
    int an=m*kuan;
    printf("%d\n",an);



    return 0;
}