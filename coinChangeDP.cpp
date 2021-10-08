#include<bits/stdc++.h>
using namespace std;

long long int coinChange(int coins[], int n , int amt){
    //coins[]= Value of coins
    //int n = No of coins
    //amt = amount
    vector<long long int> dp(amt+1,0);
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = coins[i] ; j < amt+1 ; j++){
            dp[j] +=dp[j-coins[i]];
        }
    }

    
    return dp[amt];

}

int main(){
    int n;
    cin>>n;
    int amt;
    cin>>amt;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<coinChange(arr,n,amt);
    return 0;
}

//output
4
10
2 5 3 6
5
