package work4.homeWork.homework2.project;
import work4.homeWork.homework2.control.bookManager;
public class project {
    public static void main(String[] args) {
        bookManager.InitBooks();
        System.out.println("显示所有书目:");
        bookManager.listBooks();
        System.out.println("显示价格低于50的书目:");
        bookManager.listBooks(50);
    }
}
