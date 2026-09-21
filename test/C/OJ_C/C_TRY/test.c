#include<stdio.h>
int main(){
	for(int i=1;i<10;i++){
		for(int n=1;n<i+1;n++){
			printf("%d * %d = %d",i,n,i*n);
		}
        printf("\n");
	}
	return 0;
}