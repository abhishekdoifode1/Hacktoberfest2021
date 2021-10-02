#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int MaximizeProfit(vector<int> &length, vector<int> &price, int N){
	int n = length.size();
	int dp[n+1][N+1];

	for(int i=0; i<N+1; i++)
		dp[0][i] = 0;
	for(int i=0; i<n+1; i++)
		dp[i][0] = 0;


	for(int i=1; i<n+1; i++){
		for(int j=1; j<N+1; j++){
			if(length[i-1] <= j)
				dp[i][j] = max((price[i-1] + dp[i][j-length[i-1]]), dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][N];
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> length = {1,2,3,4,5,6,7,8};
	vector<int> price = {1,5,8,9,10,17,17,20};
	int N = 8;

	// length = {1,2,3,4};
	// price = {2,5,7,8};
	// N = 5;

	cout<<"Maximize Profit: "<<MaximizeProfit(length, price, N);
}