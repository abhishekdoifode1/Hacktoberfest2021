#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int dp[1000][1000];

bool isPalindrome(string s, int i, int j){
	if(i == j)
		return true;
	if(s[i] != s[j])
		return false;

	if(i < j+1)
		return isPalindrome(s, i+1, j-1);

	return false;
}

int Solve(string &s, int i, int j){
	if(i >= j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	if(isPalindrome(s, i, j))
		return 0;
	
	int ans = INT_MAX;
	for(int k=i; k<j; k++){
		int temp = Solve(s, i, k) + Solve(s, k+1, j) + 1;
		ans = min(ans, temp);
	}
	return dp[i][j] = ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);
	memset(dp, -1, sizeof(dp));

	string s = "nitin";
	s = "ababbbabbababa";

	cout<<Solve(s, 0, s.size()-1);
}