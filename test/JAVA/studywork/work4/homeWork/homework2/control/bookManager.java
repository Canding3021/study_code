package work4.homeWork.homework2.control;
import work4.homeWork.homework2.model.book;
public class bookManager {
    public static book[] books;
    public static void InitBooks(){
        books=new book[3];
        books[0]= new book("PostgreSQL实战","9787111603467",62.3);
        books[1]= new book("ROS机器人开发实践","9787111598237",69.3);
        books[2]= new book("Java高并发编程详解","9787111599937",48.3);
    }
    public static void listBooks(){
        for(book book : books){
            book.showInfo();
        }
    }
    public static void listBooks(double price){
        for(book book : books){
            if(book.getPrice()<price){
                book.showInfo();
            }
        }
    }
}
