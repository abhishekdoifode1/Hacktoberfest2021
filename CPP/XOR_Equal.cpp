#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
#include<algorithm>
#include <vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
#include<sstream>
#include <string.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ff first 
#define ss second 
#define pp pair<ll,ll>
#define ll  long long
#define ld  long double
#define endl "\n"
 
const ll mod=1e9+7;
void solve()
{
ll  n, a=0,b=0,m=1, c=-1,k=0, i=0, j=0, l=1e9+5;
string s,p, q;
    cin>>n>>a;
    l=0;
    map<ll,ll>mp;
    map<ll,ll>pre;
    rep(i,0,n){
        cin>>b;
        mp[b]++;
        pre[b]=1;
    }
    if(n==1){
        cout<<1<<" "<<0<<endl;return;
    }   
    ll chg=0;
    for(auto x:mp){
        if(x.ss==n){
            k=n;
            break;
        }
        if(x.ss>=k) k=x.ss;
    }
    if(a==0){
        cout<<k<<" "<<chg<<endl;return;
    }
    for(auto x:mp){
        if(pre[x.ff^a]==1){
            if(x.ss+mp[x.ff^a]>k){
                k=x.ss+mp[x.ff^a];
                chg=min(x.ss,mp[x.ff^a]);
            }
            else if(x.ss+mp[x.ff^a]==k){
                if(min(x.ss,mp[x.ff^a])<chg)
                chg=min(x.ss,mp[x.ff^a]);
            }
        }
    }
    cout<<k<<" "<<chg<<endl;
}
int main()
{
ios_base::sync_with_stdio(false);
cin. tie(0);cout. tie(0);
ll t=1;
cin>>t;
while(t--)
{
solve();
}
return 0;
}