#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int MinimumSubsetSumDifference(vector<int> &v){
	int n = v.size();
	int sum = 0;

	for(int i=0; i<n; i++)
		sum += v[i];

	bool dp[n+1][sum+1];

	for(int i=0; i<sum+1; i++)
		dp[0][i] = false;
	for(int i=0; i<n+1; i++)
		dp[i][0] = true;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(v[i-1] <= j)
				dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	int tmp = sum/2;
	int mn = INT_MAX;
	// debug(tmp);
	for(int i=0; i<tmp+1; i++){
		// cout<<dp[n][i]<<" ";
		if(dp[n][i] == true){
			debug(i);
			mn = min(mn, abs(sum - 2*i));
		}
	}

	return mn;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {1,6,11,5};
	v = {1,2,7};
	v = {1,4};

	cout<<MinimumSubsetSumDifference(v);
}