#include<stdio.h>
#include<math.h>
int main(){
    int a;
    scanf("%d",&a);
    int b=1;
    for (int i=1;i<=a;i++){
        b=b*i;
    }
    printf("%d",b);

}