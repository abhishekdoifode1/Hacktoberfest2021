public class UglyNumberII {
    public static void main(String[] args) {
        int n = 10;
        System.out.println(nthUglyNumber(n));
    }

    private static int nthUglyNumber(int n) {

        int count = 0;
        int num = 0;
        while(count!=n){ 
            if (num == 0){
                num++;
                continue;
            }         
            if(num == 1 || num%3 == 0 || num%5 == 0 || num%2 == 0){
                System.out.println(count +" : "+num);
                num++;
                count++;
            }
            else{
                num++;
            }
        }
        return num;
    }
}
