import java.util.Scanner;

public class Main {
	
	static int factorial (int n) {
		if (n <= 1) {
			return 1;
		}
		return n * factorial(n - 1);
	}
	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Please enter a number: ");
		int number = sc.nextInt();
		
		System.out.println(number + "! = " + factorial(number));
		
		sc.close();
	}
}
