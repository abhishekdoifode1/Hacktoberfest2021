#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int dp[1000][1000];

int MCM(vector<int> &v, int i, int j){
	if(i >= j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	for(int k=i; k<=j-1; k++){
		int temp = MCM(v, i, k) + MCM(v, k+1, j) + v[i-1]*v[k]*v[j];
		ans = min(ans, temp);
	}
	return dp[i][j] = ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	memset(dp, -1, sizeof(dp));

	vector<int> v = {40, 20, 30, 10, 30};
	cout<<MCM(v, 1, v.size()-1);
}