class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        for(int i=1;i<=num;i++){
            if(i%2==0){
                int num=i-1;
                while(num&1)num>>=1;
                dp[i]=dp[num]+1;
            }
            else
                dp[i]=dp[i-1]+1;
        }
        return dp;
    }
};

// Created by shivam bansal
