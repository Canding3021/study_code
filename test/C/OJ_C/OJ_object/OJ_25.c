#include<stdio.h>
int main(){
    int answer=0;
    for(int x=1;x*5<100;x++){
        for(int y=1;y*2<100;y++){
            for(int z=1;z<100;z++){
                if(x*5+y*2+z==100){
                    answer++;
                }
            }
        }
    }
    printf("%d",answer);
    return 0;
}