class Solution {
    public double myPow(double x, long n) {
        if (n < 0) {
            x = 1 / x;
            n = -1 * n;
        }
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        double result = myPow(x, n / 2);
        result *= result;
        if(n % 2 != 0) {
            result = result  * x;
        }
        return result;
    }
}
