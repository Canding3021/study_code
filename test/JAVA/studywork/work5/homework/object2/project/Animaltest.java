package work5.homework.object2.project;
import work5.homework.object2.model.Animal;
import work5.homework.object2.model.Cat;
import work5.homework.object2.model.Dog;
public class Animaltest {
    public static void main(String[] args) {
        Animal animal=new Animal();
        Dog dog1=new Dog("旺财",3,"白色");
        Dog dog2=new Dog("大黄",6,"黄色");
        Cat cat1=new Cat("来福",5,"银渐层");
        Cat cat2=new Cat("奶牛",7,"奶牛猫");
        Animal[] animals=new Animal[5];
        animals[0]=animal;
        animals[1]=dog1;
        animals[2]=dog2;
        animals[3]=cat1;
        animals[4]=cat2;

        for(Animal a: animals){
            System.out.print(a.toString());
            a.Shout();
        }
    }
}
