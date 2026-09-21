#include<stdio.h>
int main(){
    int shuliang=0;
    int X,A,B;
    scanf("%d %d %d",&X,&A,&B);
    int gou,mao;
    for(gou=1;gou*A<X;gou++){
        for(mao=1;mao*B<X;mao++){
            if(gou*A+mao*B==X){
                shuliang++;
            }
        }
    }
    printf("%d",shuliang);
    return 0;
}
  