#include<stdio.h>
int main(){
    int a,b,c;
    for(a=0;a<=24;a++){
        for(b=0;b<=24-a;b++){
            c=24-a-b;
            int x=a,y=b,z=c;
            x=x-(y+z);
            y=y+y;
            z=z+z;

            y=y-(x+z);
            x=x+x;
            z=z+z;

            z=z-(x+y);
            x=x+x;
            y=y+y;
            if(x==y && y==z){
                printf("%d %d %d",a,b,c);     
            }
        }   
    }
}