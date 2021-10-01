import java.util.*;

class Solution {

    public static int lengthOfLIS(int[] a) {
        int dp[]=new int[a.length+1];
        Arrays.fill(dp,1);
        for(int i=1;i<=a.length;i++){
            int max=0;
            for(int j=1;j<i;j++){
                if(a[j-1]<a[i-1]){
                    max=Math.max(max,dp[j]);
                }
            }
            dp[i]=max+1;
        }
        int ans=0;
        for(int i:dp)
            ans=Math.max(ans,i);
        return ans;
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array :- ");
        int a=sc.nextInt();
        int arr[]=new int[a];
        System.out.println("Enter the elements of array :- ");
        for(int i=0;i<a;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("The maximum array size with increasing subsequence is :- "+lengthOfLIS(arr));
    }
}