// # Time Complexity: Primality

//     A prime is a natural number greater than  that has no positive divisors other than  and itself. Given  integers, determine the primality of each integer and print whether it is Prime or Not prime on a new line.

//     Note: If possible, try to come up with an  primality algorithm, or see what sort of optimizations you can come up with for an  algorithm. Be sure to check out the Editorial after submitting your code!

//     Function Description
//         Complete the primality function in the editor below. It should return Prime if  is prime, or Not prime.
//         primality has the following parameter(s):
//         n: an integer to test for primality

//     Input Format
//         The first line contains an integer, , denoting the number of integers to check for primality.
//         Each of the  subsequent lines contains an integer, , the number you must test for primality.

//     Output Format
//         For each integer, print whether  is Prime or Not prime on a new line.

//     Sample Input
//         3
//         12
//         5
//         7

//     Sample Output
//         Not prime
//         Prime
//         Prime

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the primality function below.
    static String primality(int n) {
    if (n < 2)
        return "Not prime";
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return "Prime";
    double num = n;
    for (int i = 2; i <= Math.sqrt(num); ++i)
    {
        if (n % i == 0)
            return "Not prime";
    }

    return "Prime";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int p = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int pItr = 0; pItr < p; pItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            String result = primality(n);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
