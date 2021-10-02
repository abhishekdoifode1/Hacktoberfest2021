#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

void PrintShortestCommonSupersequence(string x, string y){
	int n = x.size(), m = y.size();
	int dp[n+1][m+1];

	for(int i=0; i<n+1; i++)
		dp[i][0] = 0;
	for(int i=0; i<m+1; i++)
		dp[0][i] = 0;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1] == y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int lcs = dp[n][m];
	string ans = "";

	while(n>0 && m>0){
		if(x[n-1] == y[m-1]){
			ans.push_back(x[n-1]);
			n--;
			m--;
		}
		else{
			if(dp[n-1][m] > dp[n][m-1]){
				ans.push_back(x[n-1]);
				n--;
			}
			else{
				ans.push_back(y[m-1]);
				m--;
			}
		}
	}
	while(n>0){
		ans.push_back(x[n-1]);
		n--;
	}
	while(m>0){
		ans.push_back(y[m-1]);
		m--;
	}

	reverse(ans.begin(), ans.end());
	
	cout<<ans;
	return;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string x = "acbcf";
	string y = "abcdaf";

	x = "abac";
	y = "cab";

	PrintShortestCommonSupersequence(x, y);
}