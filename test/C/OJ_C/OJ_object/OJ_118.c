#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    if(num1<1000 || num1>9999 || num2<1000 || num2>9999){
        printf("error");
        return 0;
    }
    int valid=pow(num2,2);
    if(valid/10000000>=1){
        for(int n=1;valid/10000000!=0;n++){
            num2-=n;
            valid=pow(num2,2);
        }
    }
    int X[7];
    int num;
    for(int i=0;i<(num2-num1);i++){
        int valid2=0;
        num=pow((num1+i),2);
        int c=0;
        while(c<7){
            X[c]=num%10;
            num/=10;
            c++;
        }
        qsort(X,7,sizeof(int),cmp);
        for(int n=0;n<6;n++){
            if(X[n]==X[n+1]){
                valid2=1;
                break;
            }
        }
        if(valid2==0){
            printf("%d\n",(num1+i));
        }
    }
    return 0;
}

//就这样吧