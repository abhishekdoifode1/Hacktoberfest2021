#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int LIS(vector<int> &v){
	int n = v.size();
	vector<int> ans(n+1, 1);

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(v[j] < v[i]){
				ans[i] = max(ans[i], 1+ans[j]);
			}
		}
	}
	int mx = INT_MIN;
	for(int i=0; i<n; i++){
		mx = max(mx, ans[i]);
	}
	return mx;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
	// v = {50,3,10,7,40,80};
	// v = {0,1,0,3,2,3};
	v = {7,7,7,7,7,7,7};
	cout<<LIS(v);
}