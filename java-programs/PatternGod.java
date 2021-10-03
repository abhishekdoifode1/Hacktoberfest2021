/*
Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
Input Format
*/
import java.util.*;
public class Main {
    public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		System.out.print("*");
		for(int i=0;i<(n-3)/2;i++)
			System.out.print(" ");
		for(int i=0;i<(n+1)/2;i++)
			System.out.print("*");
		System.out.println();
		for(int i=0;i<(n-3)/2;i++){
			System.out.print("*");
			for(int j=0;j<(n-3)/2;j++){
				System.out.print(" ");
			}
			System.out.print("*");
			System.out.println();
		}
		for(int i=0;i<n;i++){
			System.out.print("*");
		}
		System.out.println();
		for(int i=0;i<(n-3)/2;i++)
				{for(int j=0;j<(n-3)/2+1;j++)
					System.out.print(" ");
				System.out.print("*");
				for(int j=0;j<(n-3)/2;j++)
					System.out.print(" ");
				System.out.print("*");
				System.out.println();
				}
		for(int i=0;i<(n+1)/2;i++)
			System.out.print("*");
		for(int i=0;i<(n-3)/2;i++)
			System.out.print(" ");
		System.out.print("*");

    }
}
