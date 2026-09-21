package work6.object1.model;

public class Deliveryman extends Person implements Delivery{
    public Deliveryman(String name,String job){
        super(name, job);
    }
    @Override
    public void deliver(Order order){
        order.setState("配送中");
        order.setPerson(this);
        System.out.println(getJob() + getName() +"在配送订单编号为" + order.getId() + "订单");
    }
    @Override
    public void introduction(){
        System.out.println("{姓名：" + getName() + "，职业：" + getJob() + "}");
    }
}