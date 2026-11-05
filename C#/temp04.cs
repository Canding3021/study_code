abstract class Animal
{
    protected string name;
    protected int age;
    public Animal(string name,int age)
    {
        this.name = name;
        this.age = age;
    }
    public abstract void eat();
}
class Cat : Animal
{
    public Cat(string name,int age):base(name,age){}
    public override void eat()
    {
        Console.WriteLine("Cat "+this.name+" is eating fish now.");
    }
}
class Dog : Animal
{
    public Dog(string name,int age):base(name,age){}
    public override void eat()
    {
        Console.WriteLine("Dog "+this.name+" is eating bones now.");
    }
}
class Progream
{
    static void Main()
    {
        Cat cat = new Cat("Tom",3);
        Dog dog = new Dog("Jack",4);
        cat.eat();
        dog.eat();
    }
}