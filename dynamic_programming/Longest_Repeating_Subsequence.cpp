#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int LongestRepeatingSubsequence(string s){
	int n = s.size();
	string x = s, y = s;

	int dp[n+1][n+1];
	for(int i=0; i<n+1; i++){
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			if(x[i-1] == y[j-1] && i != j){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	cout<<"Length is: "<<dp[n][n]<<endl;

	// Print ------------------
	int lcs = dp[n][n];
	int m = n;
	string ans = "";

	while(n>0 && m>0){
		if(x[n-1] == y[m-1] && m != n){
			ans.push_back(x[n-1]);
			n--;
			m--;
		}
		else{
			if(dp[n-1][m] >= dp[n][m-1]){
				n--;
			}
			else{
				m--;
			}
		}
	}

	reverse(ans.begin(), ans.end());
	
	cout<<ans<<endl;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string s = "aabebcdd";
	s = "banana";
	s = "abcd";
	s = "nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy"; // ans: "ma"
	LongestRepeatingSubsequence(s);
}