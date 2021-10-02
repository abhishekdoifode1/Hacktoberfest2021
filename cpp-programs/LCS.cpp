#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s,p,r;
    cin>>s>>p;
    ll dp[s.size()+1][p.size()+1];
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<s.size()+1;i++)
    {
        for(ll j=0;j<p.size()+1;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
        }
    }
    for(ll i=1;i<s.size()+1;i++)
    {
        for(ll j=1;j<p.size()+1;j++)
        {
            if(s[i-1]==p[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            
        }
    }
    // for printing LCS
    // ll k=s.size(),m=p.size();
    // while(k>0 && m>0)
    // {
    //     if(s[k-1]==p[m-1])
    //     {
    //         r.push_back(s[k-1]);
    //         k--;
    //         m--;
    //     }
    //     else
    //     {
    //      if(dp[k][m-1]>dp[k-1][m])
    //      m--;
    //      else
    //      k--;
    //     }
    // }
    // reverse(r.begin(),r.end());
    // cout<<r<<endl;
    cout<<dp[s.size()][p.size()]<<endl;
}