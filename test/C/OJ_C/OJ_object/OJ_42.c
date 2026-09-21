#include<stdio.h>
int cmp(const void*x,const void*y){
    return *(int*)y-*(int*)x;
}
int main(){
    int num;
    scanf("%d",&num);
    int i=0;
    int n[3];
    while(i<3){
        n[i]=(num)%10;
        num/=10;
        i++;
    }
    qsort(n,3,sizeof(int),cmp);
    int x;
    x=(n[0]*100+n[1]*10+n[2]);
    printf("%d\r",x);
    return 0;
}