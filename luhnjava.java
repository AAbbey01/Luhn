import java.util.*;
import java.util.Scanner;
import java.math.*;
public class luhnjava{



public static void main(String args[]){

    String[] result = args[0].split(" ");
    if(result[0].length()==15){
        System.out.print(fift(result[0]));
    }else{
        System.out.print(sisxt(result[0]));
    }
}

private static int sisxt(String s) {
    char[] c = {s.charAt(0),s.charAt(1),s.charAt(2),s.charAt(4)};
    String provider ="";
    switch(c[0]){
        case '4': provider = "Visa"; break;
        case '5': break;
        case '6': provider = "Discover";break;
        default: provider = "Unkown";
    }

    int sum = 0;
    for(int j = s.length(); j>0; j--){
        float i = Float.parseFloat(s);
        for(int k = 0; k<j-1;k++){
            i/=10;
            //System.out.println(i);
        }
        
        if(j%2==0){
            int da = ((int)((i%10))*2);
            if(da>9){
                da-=9;
            }
            //System.out.println(da);
            sum+=da;
        }else{
            //System.out.println((int)((i)%10));
            sum+= (int)((i)%10);
            
        }
    }
    System.out.println("Your card is a " + provider + " card");
    String t = sum%10==0?"Valid": "Invalid";
    System.out.println("Your card is " + t);
    return sum;
}




static int fift(String s){
    char c = s.charAt(0);
    String provider ="";
    switch(c){
        case '4': provider = "Visa"; break;
        case '5': break;
        case '6': provider = "Discover";break;
        default: provider = "Unkown";
    }
    long i = Long.parseLong(s);
    int sum = 0;
    for(int j = s.length(); j>=0; j--){
        if(j%2==1){
            int da = (int)((i/10^j)%10)*2;
            if(da>9){
                da-=9;
            }
            sum+=da;
        }else{
            sum+= (int)((i/10^j)%10) *2;
        }
    }
    System.out.println("Your card is a " + provider + " card");
    String t = sum%10==0?"valid": "invalid";
    System.out.println("Your card is " + t);
    return sum;
}
}

