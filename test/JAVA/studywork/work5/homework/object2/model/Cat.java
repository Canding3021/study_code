package work5.homework.object2.model;

public class Cat extends Animal{
    private String catType;
    public Cat(String animalName,int animalAge,String catType){
        super(animalName,animalAge);
        this.catType=catType;
    }
    public void setCatType(String catType) {
        this.catType = catType;
    }
    public String getCatType() {
        return catType;
    }
    @Override
    public String toString() {
        return super.toString()+"品种是"+catType;
    }
    @Override
    public void Shout(){
        System.out.println("发出了喵喵喵的叫声");
    }
}
