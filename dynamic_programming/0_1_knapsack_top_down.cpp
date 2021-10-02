#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int knapSack(int W, int wt[], int val[], int n){
	int t[n+1][W+1];
	// memset(t, -1, sizeof(t));

	for(int i=0; i<n; i++){
		for(int j=0; j<W; j++){
			if(i==0 || j==0)
				t[i][j]=0;
		}
	}
	for(int i=1; i<n+1; i++){
		for(int j=1; j<W+1; j++){
			if(wt[i-1] <= j)
				t[i][j]=max((val[i-1]+t[i-1][j-wt[i-1]]), t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	
	return t[n][W];
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	// int wt[] = {1,3,4,5};
 //    int val[] = {1,4,5,7};
 //    int W = 7;

    int wt[] = {3,4,5,7};
    int val[] = {12,40,26,42};
    int W = 12;

    int n = sizeof(wt)/sizeof(wt[0]);

    cout<<knapSack(W, wt, val, n);
}