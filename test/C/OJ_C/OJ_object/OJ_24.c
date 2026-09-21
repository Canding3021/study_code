#include<stdio.h>
int main(){
    int innum;
    scanf("%d",&innum);
    innum=innum*10;
    int answer=0;
    for(int x=1;x*8<innum;x++){
        for(int y=1;y*2<innum;y++){
            for(int z=1;z<innum;z++){
                if(x*8+y*2+z==innum && x+y+z>30){
                    answer++;
                }
            }
        }
    }
    printf("%d",answer);
    return 0;
}