package work6.object1.project;
import work6.object1.model.Deliveryman;
import work6.object1.model.Delivery;
import work6.object1.model.Order;
import work6.object1.model.Waiter;
import java.util.Scanner;
public class OrderDelManage {
    public static void main(String[] args) {
        Order order01 = new Order("0001","待配送");
	    Order order02 = new Order("0002","待配送");
        Order order03 = new Order("0003","待配送");
        Order[] orders = {order01,order02,order03};
        Delivery d1 = new Deliveryman("李四", "外卖员");
	    Delivery d2 = new Deliveryman("王五","外卖员");
	    Delivery d3 = new Waiter("张三", "服务员");
        int count = orders.length;
	        Scanner scanner = new Scanner(System.in);
 	        System.out.println("---------订单配送管理--------");
	        System.out.println("1.查询订单");
	        System.out.println("2.配送订单");
	        while (true){
	            System.out.print("请输入要进行的操作：");
	            int input = scanner.nextInt();
	            switch (input){
	                case 1:
 	                    for(int i = 0; i < orders.length; i ++){
 	                        Order order = orders[i];
	                        order.orderInfo();
	                        if(order.getState().equals("配送中")){
	                            System.out.print("配送员信息：");
	                            order.getPerson().introduction();
	                        }
	                    }
	                    break;
	                case 2:
	                    if(count == 0){
                        System.out.println("不存在需要配送的订单！");
	                    }else{
 	                        d1.deliver(orders[0]);
	                        count --;
                         d2.deliver(orders[1]);
                         count --;
	                        d3.deliver(orders[2]);
                        count --;
 	                    }
                    break;
	                case 3:
                     System.out.print("退出系统...");
                        scanner.close();
 	                     System.exit(0);
 	                     break;
	                default:
                    System.out.println("输入有误，请重新输入");
    }
}
    }
}
