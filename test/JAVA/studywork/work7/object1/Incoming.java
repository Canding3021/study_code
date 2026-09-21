package work7.object1;

import java.util.Scanner;

public class Incoming {
    static StringBuffer sb =new StringBuffer();
    static int inNum;
    public static void main(String[] args) {
        System.out.println("------食材入库记录------");
        Scanner scanner =new Scanner(System.in);
        sb.append("本次入库记录:"+"\r\n");
        boolean flag=true;
        while (flag) {
            inGoods();
            System.out.println("是否继续入库，(是输入Y,否输入N):");
            String s = scanner.next();
            if("N".equals(s.toUpperCase())){
                flag = false;
            }
        }
        System.out.print(sb.toString() + "入库总数量：" + inNum);
        scanner.close();
    }
    public static void inGoods(){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入入库信息（格式：食材名称-入库数量）：");
        String str = sc.next();
        sc.close();
        if (!str.contains("-")) {
            System.out.println("格式错误.");
        }else{
            sb.append(str+"\r\n");
            String[] arr =str.split("-");
            inNum +=Integer.valueOf(arr[1]);
        }
        
    }    
}
