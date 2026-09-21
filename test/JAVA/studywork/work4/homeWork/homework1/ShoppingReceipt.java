package work4.homeWork.homework1;

import java.util.Scanner;

public class ShoppingReceipt {
    public static product[] saveProducts(int num){
        Scanner sc=new Scanner(System.in);
        product[] products=new product[num];
        System.out.println("请依次输入商品的名称、单价和数量(格式：铅笔 2 3)");
        for(int i = 0; i < num; i ++){
	        product product = new product();
 	        product.setName(sc.next());
 	        product.setPrice(sc.nextDouble());
 	        product.setQuantity(sc.nextInt());
 	        products[i] = product;
 	    }
        sc.close();
 	    return products;
    }
    public static double totalPrice(product[] products){
 	        double totalPrice = 0;
 	        for(product product : products){
 	            totalPrice += product.getSub();
 	        }
 	        return totalPrice;
    }
    public static void printRe(product[] products){
        System.out.println("-------------小票-------------");
	        System.out.println("商品名   单价    数量    小计");
	        for(product product1 : products){
	        System.out.print(product1.getName() + "   ");
	        System.out.print(product1.getPrice() + "元    ");
 	        System.out.print(product1.getQuantity() + "    ");
 	        System.out.println(product1.getSub() + "元   ");
        }
	    System.out.println("总计: " + totalPrice(products) + "元");
        System.out.println("------------------------------");
    }
    public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        System.out.print("请输入顾客购买商品的种类数：");
	        int num = sc.nextInt();
	        product[] products = saveProducts(num);
	        printRe(products);
            sc.close();
	    }

}
