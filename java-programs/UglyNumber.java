/**
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 *
 * Example:
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * Note:
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */


import java.util.Scanner;

public class UglyNumber {
    public static int nthUglyNumber(int n) {
        int ugly[] = new int[n];
        int i2 = 0, i3 = 0, i5 = 0;
        int mul_of_2 = 2;
        int mul_of_3 = 3;
        int mul_of_5 = 5;
        int next_ugly_no = 1;

        ugly[0] = 1;
        for(int i = 1; i < n; i++)
        {
            next_ugly_no = Math.min(mul_of_2,Math.min(mul_of_3,mul_of_5));

            ugly[i] = next_ugly_no;
            if (next_ugly_no == mul_of_2)
            {
                i2 = i2+1;
                mul_of_2 = ugly[i2]*2;
            }
            if (next_ugly_no == mul_of_3)
            {
                i3 = i3+1;
                mul_of_3 = ugly[i3]*3;
            }
            if (next_ugly_no == mul_of_5)
            {
                i5 = i5+1;
                mul_of_5 = ugly[i5]*5;
            }
        }
        return next_ugly_no;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int n = nthUglyNumber(num);
        System.out.println(n);
    }
}