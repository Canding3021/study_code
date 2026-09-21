#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int N=a*3;
    int S=N-8;
    double PVER=(a+N+S)/3.0;
    printf("%d\n",N);
    printf("%d\n",S);
    printf("%.1f\n",PVER);
    return 0;
}