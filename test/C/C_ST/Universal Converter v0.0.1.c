
#include<stdio.h>
#include <windows.h>
#include <locale.h>
void print_metric_menu() {
    printf("\n=== Metric Units ===\n");
    printf("1. Picometers (pm)(皮米)\n");
    printf("2. Nanometers (nm)(纳米)\n");
    printf("3. Micrometers (µm)(微米)\n");
    printf("4. Millimeters (mm)(毫米)\n");
    printf("5. Centimeters (cm)(厘米)\n");
    printf("6. Decimeters (dm)(分米)\n");
    printf("7. Meters (m)(米)\n");
    printf("8. Kilometers (km)(千米)\n");
    printf("9. Light Years (ly)(光年)\n");
    printf("10. Astronomical Units (AU)(天文单位)\n");
    printf("Please choose a unit to convert from: ");
}

void print_imperial_menu() {
    printf("\n=== Imperial Units ===\n");
    printf("1. Inches (in)(英寸)\n");
    printf("2. Feet (ft)(英尺)\n");
    printf("3. Yards (yd)(码)\n");
    printf("4. Miles (mi)(英里)\n");
    printf("5. Nautical Miles (NM)(海里)\n");
    printf("Please choose a unit to convert from: ");
}

void print_chinese_menu() {
    printf("\n=== Chinese Units ===\n");
    printf("1. Li (里)\n");
    printf("2. Zhang (丈)\n");
    printf("3. Chi (尺)\n");
    printf("4. Cun (寸)\n");
    printf("5. Fen (分)\n");
    printf("6. Li (厘)\n");
    printf("7. Hao (毫)\n");
    printf("Please choose a unit to convert from: ");
}
void printf_main_menu(){
    printf("======= Universal Converter v0.0.1 =======\n");
    printf("--------------------------------------------\n");
    printf("+++++++ 测试特供版-作者:Canding3021 +++++++\n");
    printf("--------------------------------------------\n");
    printf("1: Length(长度)\n");
    printf("2: Weight(重量)(当前版本未实装)\n");
    printf("3: Temperature(温度)(当前版本未实装)\n");
    printf("4: Time(时间)(当前版本未实装)\n");
    printf("0: EXIT(退出)\n");
    printf("--------------------------------------------\n");
    printf("Please enter an option: ");
}

void printf_main_length_menu(){
     printf("\n====== Length Conversion Menu ======\n");
    printf("1. Metric Units (千米, 米, 皮米, etc.)\n");
    printf("2. Imperial Units (英寸, 英尺, 英里, etc.)\n");
    printf("3. Chinese Units (里, 尺, 寸, etc.)\n");
    printf("0. Exit\n");
    printf("Please choose a category: ");
}
int confirm_exit(){
    char ch;
    printf("Are you sure you want to exit this program? (Y/N):");
    scanf(" %c",&ch);
    if(ch=='y' || ch=='Y'){
        return 1;
    }
    return 0;
    system("cls");
}
int user_input(int *user_choice){
    if(*user_choice<0 || *user_choice>5){
        printf("Invalid option. Please try again.\n");
        Sleep(1000);
        return 0;
    }
    return 1;
}
int length_main_menu(int user_length_main_menu_choice){
    switch (user_length_main_menu_choice) {
                case 1:
                    printf("You selected Metric Units.\n");
                    print_metric_menu();
                    break;
                case 2:
                    printf("You selected Imperial Units.\n");
                    print_imperial_menu();
                    break;
                case 3:
                    printf("You selected Chinese Units.\n");
                    print_chinese_menu();
                    break;
                case 0:
                    printf("Exiting length menu.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }

}
int choice_back(int user_choice,int *user_length_main_menu_choice){
     switch (user_choice){
        case 1:
            system("cls");
            printf_main_length_menu();
            ("%d", &user_length_main_menu_choice);
            length_main_menu(*user_length_main_menu_choice);
            break;
        case 2:
            printf("(当前版本未实装)");
            break;
        case 3:
            printf("(当前版本未实装)");
            break;
        case 4:
            printf("(当前版本未实装)");
            break; 
        case 0:
            return -1;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;   
}

//-------------------------------------------------------------------------------------------------------
int main() {
    int user_choice;
    int user_length_main_menu_choice;
    int exit_flag = 0;
    setlocale(LC_ALL, "zh_CN.UTF-8");

    do {
        printf_main_menu();
        scanf("%d", &user_choice);

        if (user_input(&user_choice) == 0) {
            continue; 
        }
        if (choice_back(user_choice,&user_length_main_menu_choice) == -1) {
            if(confirm_exit()){
                printf("The program has ended. Thank you for using it.\n");
                Sleep(1000);
                exit_flag=1;
            }
        }
    } while (!exit_flag); 

    return 0;
}