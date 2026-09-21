package work4.homeWork.homework2.model;

public class book {
    private String bookName;
    private String isbn;
    private double price;
    public book(){

    }
    public book(String bookName,String isbn,double price){
        super();
        this.bookName=bookName;
        this.isbn=isbn;
        this.price=price;
    }
    public String getBookName() {
        return bookName;
    }
    public void setBookName(String bookName) {
        this.bookName = bookName;
    }
    public String getIsbn() {
        return isbn;
    }
    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }
    public double getPrice() {
        return price;
    }
    public void setPrice(double price) {
        this.price = price;
    }
    public void showInfo(){
        System.out.println("书名:"+bookName+"ISBN:"+isbn+"价格:"+price);
    }
}
