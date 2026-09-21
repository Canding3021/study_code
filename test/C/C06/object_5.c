#include<stdio.h>
#define M 3
#define N 2
int main(){
    int a[M][N];
    int b[M][N];
    int i,j;
    int c[M][N];
    printf("first.");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("second.");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%d",a[i][j]);
            printf(" ");
        }
        for(j=0;j<N;j++){
            printf("%d",b[i][j]);
            printf(" ");
        }
        for(j=0;j<N;j++){
            printf("%d",c[i][j]);
            printf("\n");
        }
    }
    return 0;
}