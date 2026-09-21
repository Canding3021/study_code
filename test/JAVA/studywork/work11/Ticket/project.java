package JAVA.studywork.work11.Ticket;

public class project {
    public static void main(String[] args) {
        Ticket ticket =new Ticket();
        Thread t1 =new Thread(ticket,"windows1");
        Thread t2 =new Thread(ticket,"windows2");
        Thread t3 =new Thread(ticket,"windows3");
        t1.start();
        t2.start();
        t3.start();
    }
}
