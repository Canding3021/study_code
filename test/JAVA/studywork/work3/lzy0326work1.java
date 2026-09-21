package work3;
import java.util.Random;
import java.util.Scanner;
public class lzy0326work1 {
    public static void main(String[] args){
        byte booler=0;
        Random random=new Random();
        int randomNumber=random.nextInt(100)+1;
        int user_gress_number;
        System.out.println("The gress game start,please enter a number between 1 to 100:");
        Scanner scanner=new Scanner(System.in);
        while (booler==0) {
            System.out.println("enter a number:");
            user_gress_number=scanner.nextInt();
            if(user_gress_number==randomNumber){
                System.out.println("you are right.");
                booler++;
            }else if(user_gress_number<randomNumber){
                System.out.println("small.");
            }else if(user_gress_number>randomNumber){
                System.out.println("big.");
            }
        }
        scanner.close();
    }
    
}