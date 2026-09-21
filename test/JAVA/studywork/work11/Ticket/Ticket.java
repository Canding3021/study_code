package JAVA.studywork.work11.Ticket;

public class Ticket implements Runnable{
    int ticket=100;
    Object lock =new Object();
    @Override
    public void run(){
        while (true) {
            synchronized(lock){
                if(ticket > 0){
                    try{
                        Thread.sleep(10); // 拿到了锁，模拟售票耗时
                    } catch(InterruptedException e){
                        e.printStackTrace();
                    }
                    String win = Thread.currentThread().getName();
                    System.out.println(win + "正在卖" + ticket--);
                } else {
                    break; // 票卖完了，退出循环
                }
            } // 锁在这里被释放
            
            // 【关键改进】：在锁外面稍微歇一下，把抢锁的机会公平地让给其他窗口
            try {
                Thread.sleep(5); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

