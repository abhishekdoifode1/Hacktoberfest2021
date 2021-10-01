
//check if a number is perfect square using binary search

import java.util.Scanner;

public class perfectsquare {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        boolean ans = isPerfectSquare(num);
        System.out.println(ans);

    }
    static boolean isPerfectSquare(int num) {


        int s = 1;
        int l = num;
        if(num==0||num==1){return true;}


        while(s<=l){
            int mid = s+ (l-s)/2;

            if(mid==num/mid && num%mid==0){
                return true;
            }
            if(mid>num/mid){
                l = mid+1;
            }else{
                l = mid-1;
            }
        }
        return false;

    }
}
