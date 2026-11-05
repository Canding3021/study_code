public delegate int Max(int first,int second);
class EventExample
{
    public delegate void DelegateMax(int first,int second);
    public event DelegateMax EventMax;
    public void IntMax(int a,int b)
    {
        Console.WriteLine("Between the two number {0} and {1}.The biggest number is:");
        EventMax(a,b);
    }
}
class Progream
{
    static void Main()
    {
        EventExample ee = new EventExample();
        ee.EventMax += new EventExample.DelegateMax(ee_EventMax);
        ee.IntMax(2,3);
        Console.ReadKey();
    }
    static void ee_EventMax(int first,int second)
    {
        if (first > second)
        {
            Console.WriteLine(first);
        }
        else
        {
            Console.WriteLine(second);
        }
    }
}