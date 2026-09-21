#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    srand((unsigned)time(NULL));
    int target;
    int guess;
    int user_choose;
    target=((rand()%100)+1);
    printf("1.do whlie\n2.while\n3.for\n");
    scanf("%d",&user_choose);
    if(user_choose<=0 || user_choose>3){
        return(-1);
    }
    switch (user_choose)
    {
    case 1:
            do
        {
            printf("Please enter a number:");
            scanf("%d",&guess);
            if(guess==target){
                printf("you win.");
                break;
            }else if (guess<target)
            {
                printf("small.\n");
                continue;
            }else if (guess>target)
            {
                printf("big.\n");
                continue;
            }
        }
        while (guess!=target);
        break;

        case 2:
        while(guess!=target){
            printf("Please enter a number:");
            scanf("%d",&guess);
            if(guess==target){
                break;
            }else if (guess<target)
            {
                printf("small.\n");
                continue;
            }else if (guess>target)
            {
                printf("big.\n");
                continue;
            }
        }printf("you win.");
        break;

        case 3:
        for(int i=0;i!=1;){
            printf("Please enter a number:");
            scanf("%d",&guess);
            if(guess==target){
                i++;
                break;
            }else if (guess<target)
            {
                printf("small.\n");
                continue;
            }else if (guess>target)
            {
                printf("big.\n");
                continue;
            }
        }printf("you win.");
    default:
        break;
    }
    return 0;
}