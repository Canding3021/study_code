package work2;
import java.util.Scanner;
public class lzy0326work3 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String name;
        double money;
        int year;
        System.out.print("请输入您的名称:");
        name=sc.nextLine();
        System.out.print("请输入你的月薪:");
        money=Double.parseDouble(sc.nextLine());
        System.out.print("请输入您的工龄:");
        year=Integer.parseInt(sc.nextLine());
        sc.close();
        double output_money=0;
        output_money=(money*12)+((year/2)*money);
        System.out.println("姓名:"+name);
        System.out.println("年薪="+output_money);
    }
}
