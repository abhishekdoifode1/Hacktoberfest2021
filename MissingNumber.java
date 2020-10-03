import java.util.*;

public class MissingNumber{
	public static void main(String args[]) 
	{
		//Given an array of size n-1 ,return the missing number in [1-n];
		//array contains no duplicate numbers
		
        	Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		int sum = 0;
		for(int i = 0 ; i < n - 1 ; i++)
			sum+=scanner.nextInt();
		
		int missingNumber = (n*(n+1))/2 - sum;

		System.out.println("The missing number is "+missingNumber);
	}
}