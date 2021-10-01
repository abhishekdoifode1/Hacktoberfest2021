//An algorithm to find out the twin prime in a range.
/**
 * A twin prime is a prime number that is either 2 less or 2 more than another prime number 
 * for example, either member of the twin prime pair (41, 43). 
 * In other words, a twin prime is a prime that has a prime gap of two.
 */
//By @namratapdr
import java.util.*;

class twinPrime {
  static int isprime(int num){
    for(int i=2;i<=(int)Math.sqrt(num);i++){
      if (num%i ==0){
        return 0;
      }
    }
    return 1;
  }
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter the start value of range: ");
      int srange = sc.nextInt();
       System.out.println("Enter the end value of range: ");
       int range = sc.nextInt();
      if (srange<range && srange>0 && range>0)
      {
        int copy=srange;
        if (srange < 2)
              copy = 2;

        System.out.println("The twin prime numbers from "+srange+" to "+range+" is: ");
        for(int i=copy; i<=range;i++){
            if(isprime(i)==1){
                if(isprime(i+2)==1)
                  System.out.println(i + "\t"+ (i+2));
            }
        }
      }
      else{
        System.out.println("Enter a valid range.Try Again!");
        main(args);
      }
      sc.close();
}
}