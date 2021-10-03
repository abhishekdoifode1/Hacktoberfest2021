/*
    Problem Link:
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0, high=1, profit=0;
        while(high<prices.size()){
            if(prices[low]>=prices[high]){
                low=high; high++;
            }
            else{
                profit=max(profit, prices[high]-prices[low]);
                high++;
            }
        }
        return profit;
    }
};