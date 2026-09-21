#include<stdio.h>
#include<math.h>
int main(){
    int firnum;
    int sednum;
    scanf("%d %d",&firnum,&sednum);
    int ansy=firnum/sednum;
    int anss=firnum%sednum;
    printf("%d %d",ansy,anss);

    return 0;
}