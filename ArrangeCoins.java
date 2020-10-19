public class ArrangeCoins {
    public static void main(String[] args) {
        
        long n = 2147483647;
        System.out.println(arrangeCoins(n));
    }

    public static int arrangeCoins(Long n) {
        
        if (n == 0){
            return 0;
        }

        int count_steps = 1 ;

        for(int i = 1; i < n + 1; i++){
            
            if(count_steps <= n ){
                n = n - i;
                // System.out.println(count_steps);
                count_steps++;
                continue;
            }
            else{
                break;
            }
        }

        return count_steps - 1;
    }
}
