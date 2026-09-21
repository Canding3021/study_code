#include<stdio.h>
int main(){
    int x,y,z;
    int i=0;
    for(x=0;x*9<100 && x*2<100;x++){
        for(y=0;y<100 && y*2<100;y++){
            for(z=0;z<100 && z*4<100;z++){
                if(x*9+y+z==100 && x*2+y*2+z*4==100){
                    printf("%d %d %d",x,y,z);
                    printf("\n");
                    i++;
                }
            }
        }
    }
    printf("%d",i);



    return 0;
}