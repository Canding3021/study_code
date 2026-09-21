package work6.object1.model;

public class Order {
    private String id;
    private String state;
    private Person person;
    public Order(String id,String state){
        this.id=id;
        this.state=state;
    }
    public String getId() {
        return id;
    }
    public String getState() {
        return state;
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setState(String state) {
        this.state = state;
    }
    public Person getPerson() {
        return person;
    }
    public void setPerson(Person person) {
        this.person = person;
    }
    public void orderInfo(){
        System.out.println("订单编号：" + this.id + ",订单状态：" + this.state);
    }

}
