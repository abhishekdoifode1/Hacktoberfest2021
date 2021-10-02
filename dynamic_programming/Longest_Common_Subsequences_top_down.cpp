#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int LongestCommonSubsequence(string x, string y, int n, int m){
	int dp[n+1][m+1] = {0};
	// memset(dp, -1, sizeof(dp));

	for(int i=0; i<m+1; i++)
		dp[0][i] = 0;
	for(int i=0; i<n+1; i++)
		dp[i][0] = 0;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1] == y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}

	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return dp[n][m];
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string x = "abcdgh";
	string y = "abedfhl";

	// x = "abcdgh";
	// y = "aedfhr";

	// x = "abc";
	// y = "def";

	x = "abc";
	y = "abcd";

	int n = x.size();
	int m = y.size();

	cout<<LongestCommonSubsequence(x, y, n, m)<<endl;
}