//多边形内角度数
#include<stdio.h>
#include<math.h>
int main(){
    int N;
    scanf("%d",&N);
    if(N>=3 && N<=10){
        double an=((N-2)*180)/N;
        printf("%.1f",an);
    }
    else return 1;
    return 0;

}



////为啥OJ不判我对啊？？？？？？