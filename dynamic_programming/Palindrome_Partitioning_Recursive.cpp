#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

bool isPalindrome(string &s, int i, int j){
	if(s[i] != s[j])
		return false;
	if(i == j)
		return true;
	if(i < j+1)
		return isPalindrome(s, i+1, j-1);
	return true;
}

int PalindromePartitioningRecursive(string &s, int i, int j){
	if(i >= j)
		return 0;

	if(isPalindrome(s, i, j))
		return 0;

	int ans = INT_MAX;
	for(int k=i; k<=j-1; k++){
		int temp = PalindromePartitioningRecursive(s, i, k) + PalindromePartitioningRecursive(s, k+1, j) + 1;
		ans = min(ans, temp);
	}

	return ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string s = "nitin";
	s = "aaaa";
	s = "abcde";
	s = "abbac";

	cout<<PalindromePartitioningRecursive(s, 0, s.size()-1);
}