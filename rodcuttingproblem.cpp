#include<bits/stdc++.h>
using namespace std;

int isSubset(int wt[], int val[], int n)
{
	int subset[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
		subset[0][i] = 0;
	for (int i = 0; i <= n; i++)
		subset[i][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (wt[i - 1] > j)
				subset[i][j] = subset[i - 1][j];
			else
				subset[i][j] = max(val[i - 1] + subset[i][j - wt[i - 1]], subset[i - 1][j]);
		}
	}
	return subset[n][n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int wt[n], val[n];
		for (int i = 0; i < n; i++)
			cin >> wt[i];
		for (int i = 0; i < n; i++)
			cin >> val[i];
		cout << isSubset(wt, val, n) << "\n";
	}
	return 0;
}