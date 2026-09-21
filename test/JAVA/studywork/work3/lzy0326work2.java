package work3;
import java.util.Scanner;
public class lzy0326work2 {
    public static void main(String[] args){
        int user_input_number;
        Scanner scan=new Scanner(System.in);
        System.out.println("Please enter a number:");
        user_input_number=scan.nextInt();
        scan.close();
        if(user_input_number<100 || user_input_number>1000){
            System.out.println("number error");
        }else{
            if(Math.pow((user_input_number/100),3)+Math.pow((user_input_number/10%10),3)+Math.pow((user_input_number%10),3)==user_input_number){
                System.out.println("this is a Narcissistic number.");
            }else{
                System.out.println("this is not a Narcissistic number.");
            }
        }
    }
}
