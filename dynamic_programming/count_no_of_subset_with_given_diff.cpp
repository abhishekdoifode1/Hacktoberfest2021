#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int CountNoOfSubsetWithGivenSum(vector<int> &v, int diff){
	int n = v.size();
	int sum = 0;

	for(int i=0; i<n; i++)
		sum += v[i];

	int dp[n+1][sum+1];

	for(int i=0; i<sum+1; i++)
		dp[0][i] = 0;
	for(int i=0; i<n+1; i++)
		dp[i][0] = 1;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(v[i-1] <= j)
				dp[i][j] = dp[i-1][j-v[i-1]] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	int sum_s1 = (diff+sum)/2;

	return dp[n][sum_s1];
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {1,1,2,3};
	int diff = 1;

	cout<<CountNoOfSubsetWithGivenSum(v, diff);
}