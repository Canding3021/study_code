using System;
class Animal
{
    private string type;

    public string Type 
    {
        get { return type; }
        set { type = value; }
    }

    public Animal()
    {
        type = "未知";
        Console.WriteLine("调用Animal的无参构造函数");
    }

    public Animal(string type)
    {
        this.type = type;
        Console.WriteLine("调用Animal的带参构造函数, type = " + type);
    }

    public override string ToString()
    {
        return "这是一个动物类";
    }

    public virtual void sound()
    {
        Console.WriteLine("动物发出声音");
    }
}
class Cat : Animal
{
    private string name;
    private string color;

    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public string Color
    {
        get { return color; }
        set { color = value; }
    }

    public Cat() : base("猫科")
    {
        name = "无名猫";
        color = "白色";
        Console.WriteLine("调用Cat的无参构造函数");
    }

    public Cat(string name, string color) : base("猫科")
    {
        this.name = name;
        this.color = color;
        Console.WriteLine("调用Cat的带参构造函数, name = " + name);
    }

    public override string ToString()
    {
        return "猫猫的名字是" + name + "，颜色是" + color + "，它属于" + Type;
    }

    public override void sound()
    {
        Console.WriteLine("喵喵叫");
    }

    public void climbTree()
    {
        Console.WriteLine(name + " 会爬树");
    }
}

class Dog : Animal
{
    private string name;
    private string breed;

    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public string Breed
    {
        get { return breed; }
        set { breed = value; }
    }

    public Dog() : base("犬科")
    {
        name = "无名狗";
        breed = "土狗";
        Console.WriteLine("调用Dog的无参构造函数");
    }

    public Dog(string name, string breed) : base("犬科")
    {
        this.name = name;
        this.breed = breed;
        Console.WriteLine("调用Dog的带参构造函数, name = " + name);
    }

    public override string ToString()
    {
        return "狗狗的名字是" + name + "，品种是" + breed + "，它属于" + Type;
    }

    public override void sound()
    {
        Console.WriteLine("汪汪叫");
    }

    public void watchHouse()
    {
        Console.WriteLine(name + " 会看家");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Dog d = new Dog();
        d.Type = "哺乳类";
        d.Name = "Tom";
        Console.WriteLine(d.ToString());
        d.sound();
        d.watchHouse();
        Cat c = new Cat("Kitty", "橘色");
        c.Type = "哺乳类";
        Console.WriteLine(c.ToString());
        c.sound();
        c.climbTree();
        Animal a = new Dog("Jack", "金毛");
        Console.WriteLine(a.ToString());
        a.sound();
    }
}
