package JAVA.temp;
public class temp{
    public static void main(String[] args) {
        int[] a={10,42,56,82,26,35,91,47,26,1};
        for(int i=1;i<=10;i++){
            int t=a[0];
            int temp=a[i-1];
            if(t>temp){
                a[i-1]=temp;
            }else{
                a[i+1]=temp;
            }
        }
        System.out.println(a);
    }
}