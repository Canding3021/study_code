package work2;
import java.util.Scanner;
public class lzy0326work2 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int user_choice=0;
        System.out.println("1+   2-  3*   4/");
        user_choice=sc.nextInt();
        double user_input_1=0;
        double user_input_2=0;
        System.out.println("请输入两个数字");
        user_input_1=sc.nextDouble();
        user_input_2=sc.nextDouble();
        sc.close();
        double output=0;
        switch (user_choice) {
            case 1:
                output=user_input_1+user_input_2;
                System.out.println(output);
                break;
            case 2:
                output=user_input_1-user_input_2;
                System.out.println(output);
                break;
            case 3:
                output=user_input_1*user_input_2;
                System.out.println(output);
                break;
            case 4:
                if(user_input_2==0){
                    System.out.println("除数不能为0");
                }else{
                output=user_input_1/user_input_2;
                System.out.println(output);
                }
                break;
            default:
                System.out.println("未知选项");
        }
    }
}
