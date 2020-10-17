/**
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are different.
 *
 */



import java.util.Scanner;

public class HammingDistance {
    public static int hammingDistance(int x, int y) {
        int res = x ^ y;
        int bits = 0;
        while (res > 0)
        {
            bits += res & 1;
            res >>= 1;
        }
        return bits;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = 1;
        int y = 4;
        int find = hammingDistance(x,y);
        System.out.println(find);
    }
}
