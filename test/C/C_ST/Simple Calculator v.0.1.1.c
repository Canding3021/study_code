#include<stdio.h>

#include<math.h>

#include <windows.h>//v0.0.6版本修改了用户无法看见结束语的问题

#include <stdlib.h>//v0.0.7b试图实现清屏操作，但是失败了

double add(double a,double b){
    return a+b;
}
double sub(double a,double b){
    return a-b;
}
double mul(double a,double b){
    return a*b;
}
double divide(double a,double b,double *result){
    if(b==0){
        return 0;
    } 
    *result=a/b;
    return 1;
}
double exponent(double a,double b){
    return pow(a,b);
}

//在测试输入时要注意0不可做为除数。2025.11.24   v0.0.2

int confirm_exit(){
    char ch;
    printf("Are you sure you want to exit this program? (Y/N):");
    scanf(" %c",&ch);
    if(ch=='y' || ch=='Y'){
        return 1;
    }
    system("cls");
    return 0;
}

//每次不小心就给我切出去了，，还要重头开始，多添加一轮判断准没错。2025.11.27      v0.0.3



void print_menu() {
    printf("\n====== Simple Calculator v0.1.1 ======\n");
    printf("---------------------------------------\n");
    printf("1. Addition(+)\n");
    printf("2. Subtraction(-)\n");
    printf("3. Multiplication(*)\n");
    printf("4. Division(/)\n");
    printf("5. Exponent(^)\n");
    printf("0. Exit\n");
    printf("---------------------------------------\n");
    printf("Please enter an option: ");
}

//v.0.0.5版本封装了菜单

void answer_back(int user_choice,double x,double y){
    double result;
    switch (user_choice){
            case 1:
                printf("Result:%.2lf\n",add(x,y));
                break;
            case 2:
                printf("Result:%.2lf\n",sub(x,y));
                break;
            case 3:
                printf("Result:%.2lf\n",mul(x,y));
                break;
            case 4:
                if(divide(x,y,&result)){
                    printf("Result:%.2lf\n",result);
                }
                else{
                    printf("Error: divisor cannot be 0. Returning to main menu.\n");
                }
                break;
            case 5:
                printf("Result:%.2lf\n",exponent(x,y));
                break; 
        }
}

int user_input(int *user_choice, double *x, double *y){
    scanf("%d",user_choice);
    if(*user_choice<0 || *user_choice>5){
        printf("Invalid option. Please try again.\n");
        Sleep(1000);
        return 0;
    }
    if(*user_choice==0){
        return -1;
    }
    printf("Enter first number: ");
    scanf("%lf",x);
    printf("Enter second number: ");
    scanf("%lf",y);
    return 1;
}
//封装了switch1的处理部分。
int main(){
    int user_choice;
    double x,y,result;
    int exit_flag=0;
    do{
        print_menu();
        if (user_input(&user_choice, &x, &y) == -1) {
            if(confirm_exit()){
                printf("The program has ended. Thank you for using it.\n");
                Sleep(1000);
                exit_flag=1;
            }
        }
        else{
            answer_back(user_choice,x,y);
            continue;    
        }    
    }
    while(!exit_flag);  //v.0.0.4版本修复了无法正常退出的情况2025.11.27
    return 0;
}