#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

bool SubsetSum(vector<int> &v, int sum){
	int n = v.size();

	int t[n+1][sum+1];

	for(int i=0; i<sum+1; i++)
		t[0][i] = false;
	for(int i=0; i<n+1; i++)
		t[i][0] = true;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(v[i-1] <= j)
				t[i][j] = t[i-1][j-v[i-1]] || t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}	
	}
	return t[n][sum];
}

bool EqualSumPartition(vector<int> &v){
	int sm = 0;
	for(int i=0; i<v.size(); i++)
		sm += v[i];

	if(sm&1)
		return false;

	return SubsetSum(v, sm/2);
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {1,5,11,5};

	cout<<EqualSumPartition(v);

}