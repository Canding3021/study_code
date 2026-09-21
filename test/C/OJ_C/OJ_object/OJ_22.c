#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int cmp2(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}
int main(){
    int X,Y,Z;
    int i=1,n=1,l=1;
    int numx[1000],numy[1000],numz[1000];
    for(int X=1;X*5<100;X++){
        for(int Y=1;Y*3<100;Y++){
            for(int Z=3;Z<100;Z+=3){
                if(X+Y+Z==100){
                    numx[i]+=X;
                    numy[n]+=Y;
                    numz[l]+=Z;
                    i++;
                    n++;
                    l++;
                }
            }
        }
    }
    qsort(numx,i,sizeof(int),cmp1);
    qsort(numy,n,sizeof(int),cmp2);
    qsort(numz,l,sizeof(int),cmp2);
    for(int g=0;g<i || g<n || g<l;g++){
        printf("%d %d %d",numx[g],numy[g],numz[g]);
    }
    return 0;
}