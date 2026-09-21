package work2;

import java.util.Scanner;

public class lzy0326work4 {
    public static void main (String[] args){
        Scanner scanner=new Scanner(System.in);
        double user_input_pay=0;
        System.out.print("您的消费为:");
        user_input_pay=scanner.nextDouble();
        double output_pay=0;
        if(user_input_pay>=25 && user_input_pay<35){
            output_pay=user_input_pay-8;
        }else if(user_input_pay>=35 && user_input_pay <50){
            output_pay=user_input_pay-15;
        }else if (user_input_pay>=50) {
            output_pay=user_input_pay-20;
        }else{
            output_pay=user_input_pay;
        }
        System.out.println("您应付款为:"+output_pay);
        double user_input=0;
        System.out.print("您已付款:");
        user_input=scanner.nextDouble();
        if(user_input==output_pay){
            System.out.println("钱正好");
        }else if (user_input<output_pay){
            System.out.println("钱不够");
        }else{
            double a=user_input-output_pay;
            System.out.println("应找零:"+a);
        }
        scanner.close();
    }
}
