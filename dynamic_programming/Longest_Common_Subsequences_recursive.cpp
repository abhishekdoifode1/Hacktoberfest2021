#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int LongestCommonSubsequence(string x, string y, int n, int m){
	// Base Condition
	if(n==0 || m==0)
		return 0;

	if(x[n-1] == y[m-1]){
		return 1 + LongestCommonSubsequence(x, y, n-1, m-1);
	}
	else{
		return max(LongestCommonSubsequence(x, y, n-1, m), LongestCommonSubsequence(x, y, n, m-1));
	}
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string x = "abcdgh";
	string y = "abedfhl";

	x = "abcdgh";
	y = "aedfhr";

	x = "abc";
	y = "ac";

	int n = x.size();
	int m = y.size();

	cout<<LongestCommonSubsequence(x, y, n, m);
}