#include<bits/stdc++.h>
using namespace std;

#define int long long

void cpc()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int palpart(string s)
{
	int n = s.length();

	bool ispal[n][n];

	for (int i = 0; i < n; i++)
	{ispal[i][i] = 1;}

	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{ispal[i][i + 1] = 1;}
		else
		{ispal[i][i + 1] = 0;}
	}

	for (int gap = 2; gap < n; gap++)
	{
		for (int i = 0; i < n - gap; i++)
		{
			if (s[i] == s[i + gap])
			{ispal[i][i + gap] = ispal[i + 1][i + gap - 1];}
			else
			{ispal[i][i + gap] = 0;}
		}
	}

	int dp[n][n];

	for (int i = 0; i < n; i++)
		dp[i][i] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 0;
		else
			dp[i][i + 1] = 1;
	}

	for (int gap = 2; gap < n; gap++)
	{

		for (int i = 0; i < n - gap; i++)
		{
			dp[i][i + gap] = gap;
			if (ispal[i][i + gap])
			{dp[i][i + gap] = 0;}
			else {
				for (int k = i; k < i + gap; k++)
					dp[i][i + gap] = min(dp[i][i + gap], 1 + dp[i][k] + dp[k + 1][i + gap]);
			}
		}
	}

	return dp[0][n - 1];

}


int32_t main()
{
	cpc();

	string s;
	cin >> s;

	cout << palpart(s);
	return 0;
}
