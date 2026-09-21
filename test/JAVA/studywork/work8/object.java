package work8;

import java.util.Random;

public class object {
    public static void main(String[] args) {
        Random random= new Random();
            for(int i=0;i<50;i++){
                int result=0;
                while (result<20 || result>100) {
                int randomNumber1=random.nextInt(81)+20;
                int randomNumber2=random.nextInt(81)+20;
                if(random.nextBoolean()){
                    result=randomNumber1+randomNumber2;
                    if (result >= 20 && result <= 100) {
                        System.out.println(result + "=" + randomNumber1 + "+" + randomNumber2);
                    } else {
                        result = 0;
                    }
                }else{
                    if(randomNumber1>randomNumber2){
                        result=randomNumber1-randomNumber2;
                    }else{
                        result=randomNumber2-randomNumber1;
                    }
                    if (result >= 20 && result <= 100) {
                        System.out.println(result + "=" + Math.max(randomNumber1, randomNumber2) 
                                         + "-" + Math.min(randomNumber1, randomNumber2));
                    } else {
                        result = 0;
                    }    
                }
            }    
        }
    }
}

