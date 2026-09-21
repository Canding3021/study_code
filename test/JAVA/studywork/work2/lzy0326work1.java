package work2;
import java.util.Scanner;
public class lzy0326work1 {
    public static void main(String[] args) {
        Scanner scan= new Scanner(System.in);
        int age;
        age=scan.nextInt();
        String info =age>18?"成年人":"未成年人";
        scan.close();
        System.out.println(info);
    }
}
