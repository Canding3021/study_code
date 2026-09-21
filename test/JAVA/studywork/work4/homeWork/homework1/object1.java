package work4.homeWork.homework1;
class product{
    private String name;
    private double price;
    private int quantity;
    private double sub;
    public void setName(String name) {
        this.name = name;
    }
    public void setPrice(double price) {
        this.price = price;
    }
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
    public void setSub(double sub) {
        this.sub = sub;
    }
    public String getName() {
        return name;
    }
    public double getPrice() {
        return price;
    }
    public int getQuantity() {
        return quantity;
    }
    public double getSub() {
        sub=price*quantity;
        return sub;
    } 
    
}
public class object1 {
    public static void main(String[] args){
        
    }
}
