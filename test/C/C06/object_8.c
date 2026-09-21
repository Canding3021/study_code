#include<stdio.h>
#include<math.h>
float aver(int a,float num[a]){
    int i;
    for(i=0;i<5;i++){
        num[i]+=pow(num[i],0.5)*10.0;
    }
}
int main(){
    int a;
    printf("5");
    scanf("%d",&a);
    float sco[a];
    int i;
    printf("input 5 scores:\n");
    for(i=0;i<5;i++){
        scanf("%2f",&sco[i]);
    }
    aver(a,sco);
    for(i = 0; i < 5; i++) {
        printf("sco[%d] = %.2f\n", i, sco[i]);
    }
}