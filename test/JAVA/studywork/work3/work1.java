package work3;

import java.util.Scanner;

public class work1 {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        System.out.println("please enter the number of students.");
        int num=scanner.nextInt();
        String[] str =new String[num];
        for(int i=0;i<num;i++){
            System.out.println("please enter the name of the student:");
            str[i]=scanner.next();
        }
        for(String name : str){
            System.out.print(name);
            System.out.print(",");
        }
        scanner.close();

    }
}
