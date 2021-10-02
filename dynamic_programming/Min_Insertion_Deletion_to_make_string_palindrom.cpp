#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int lcs(string x, string y){
	int n = x.size(), m = y.size();
	int dp[n+1][m+1];

	for(int i=0; i<n+1; i++)
		dp[i][0]=0;
	for(int i=0; i<m+1; i++)
		dp[0][i]=0;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(x[i-1] == y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int MakeStringPalindrom(string s){
	string s1 = s;
	reverse(s1.begin(), s1.end());

	return s.size() - lcs(s, s1);
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string s = "agbcba";

	// No of insertion and no of deletion is same to make string palindrom
	cout<<"Minimum no of Insertion needed to make string palindromic: "<<MakeStringPalindrom(s)<<endl;
	cout<<"Minimum no of Deletion needed to make string palindromic: "<<MakeStringPalindrom(s);
}