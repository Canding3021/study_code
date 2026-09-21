package work3;

public class lzy0326work3 {
    public static void main(String[] args){
        int[] arr={52,63,1,14,36,95,6,10,27,40};
        int max=arr[0];
        int count=-1;
        for(int i=1;i<arr.length;i++){
            if(arr[i]>max){
                max=arr[i];
            }else count++;
        }
        System.out.println("The max number is:"+max);
        System.out.println("Its at the "+count+" of the arr.");
    }
}
