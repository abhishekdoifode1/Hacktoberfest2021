// # Flipping Bits
//     You will be given a list of 32 bit unsigned integers. Flip all the bits ( and ) and print the result as an unsigned integer.

//     Function Description
//         Complete the flippingBits function in the editor below. It should return the unsigned decimal integer result.

//     flippingBits has the following parameter(s):
//         n: an integer

//     Input Format
//         The first line of the input contains the number of queries.
//         Each of the next  lines contain an integer to process.


//     Output Format
//         Output one line per element from the list with the decimal value of the resulting unsigned integer.

//     Sample Input 0
//         3
//         2147483647
//         1
//         0

//     Sample Output 0
//         2147483648
//         4294967294
//         4294967295


//     Sample Input 1
//         2
//         4
//         123456

//     Sample Output 1
//         4294967291
  
//         4294843839


//     Sample Input 2
//         3
//         0
//         802743475
//         35601423

//     Sample Output 2
//         4294967295
//         3492223820
//         4259365872

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the flippingBits function below.
    static long flippingBits(long n) {
        int[] num = new int[32];
        Arrays.fill(num,0);
        int i = 0;
         while (n != 0)
    {
        num[i++] = (int)n % 2;
        n /= 2;
    }

    long res = 0, base = 1;
    
    for (i = 0; i < 32; ++i, base *= 2)
    {
        if (num[i] == 0)
            res += base;
    }
        return res;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            long n = scanner.nextLong();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            long result = flippingBits(n);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
