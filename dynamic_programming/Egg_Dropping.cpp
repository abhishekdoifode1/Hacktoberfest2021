#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int dp[200][10010];

int EggDropping(int e, int f){
	if(f == 0 || f == 1)
		return f;
	if(e == 1)
		return f;

	if(dp[e][f] != -1)
		return dp[e][f];

	int ans = INT_MAX;
	for(int k=1; k<=f; k++){
		// int temp = 1 + max(EggDropping(e-1, k-1), EggDropping(e, f-k));
		// ans = min(ans, temp);

		// --------- Memory Optimization -----------------

		int low, high;
        if(dp[e-1][k-1] != -1){
            low = dp[e-1][k-1];
        }
        else{
            low = EggDropping(e-1, k-1);
            dp[e-1][k-1] = low;
        }
        
        if(dp[e][f-k] != -1){
            high = dp[e][f-k];
        }
        else{
            high = EggDropping(e, f-k);
            dp[e][f-k] = high;
        }

        int temp = 1 + max(low, high);
        ans = min(ans, temp);
	}
	return dp[e][f] = ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	memset(dp, -1, sizeof(dp));

	int e = 3;
	int f = 5;

	e = 4;
	f = 3;

	e = 7;
	f = 10000;

	e = 2;
	f = 10;

	cout<<EggDropping(e, f);
}