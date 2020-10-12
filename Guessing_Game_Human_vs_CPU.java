import java.util.*;
import java.util.*;
public class Guessing_Game_Human_vs_CPU
{
    public static int computerGuess(int lower,int upper,int randnum,int count)
    {
        int guess=(lower+upper)/2;
        if(guess==randnum)
        return count;
        
        if(guess<randnum){
            count++;
            return computerGuess(guess,upper,randnum,count);
        } 
        
        if(guess>randnum){
            count++;
            return computerGuess(lower,guess,randnum,count);
        } 
        return -1;
    }
    
    public static void main(String[] args)
    {
      final Scanner sc=new Scanner(System.in);
      char ch='Y';  
      //the game resets if select Y else exits
      while(ch=='Y')
      {
        //Generating a random integer number Between 1 to 100
        int randnum=(int)(Math.random()*100+1);
        //Math.random gives adouble between 0 and 1 so multiply by 100 so gives between 0 to 99 and 1 for 0 to 100
        
        int chances=10;
        while(chances>0)  //while attempts are less than 10
        {       
            System.out.print("Guesss A Number between 1 to 100:");
             int guess=sc.nextInt();
            //input the guessed Number
            
            if(guess==randnum){
                System.out.println("Congrats you guessed the number !!\n");
                break;
            }
            else if(guess>randnum){
                System.out.println("Your guess is higher than the number.\n");
            }
            else{
                System.out.println("Your guess is lower than the number.\n");
            }

            chances--;
        }

        if(chances!=0){
        System.out.println("\nYou guessed the Number in "+(10-chances)+" attempts.");
        System.out.println("You scored "+(chances*10)+" points."); 
       }
       else{
        System.out.println("\nYou were not able to guess the number in 10 attempts.\n Better Luck next Time");
        System.out.println("You scored 0 points.");
       }
       int steps=computerGuess(0,100,randnum,0);
       System.out.println("\nComputer solved it in "+steps+" attempts.");
       
       if((10-chances)<steps)
       System.out.println("\nYou Beat the Computer");
       else
       System.out.println("\nYou Lost to the Computer");
       
       //check if want to continue the game or exit
       System.out.println("\nDo You want to TRY AGAIN:(Y-YES/N-NO)");
       ch=sc.next().charAt(0);
      } 
      System.out.println("\nThank you Playing!!");
    }
}
