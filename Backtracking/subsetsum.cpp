/*
Problem Statement:
      Subset sum problem is to find subset of elements that are selected 
      from a given set whose sum adds up to a given number K. We are 
      considering the set contains non-negative values. It is assumed that 
      the input set is unique (no duplicates are presented).
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define endl ("\n")
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,l,r)  for(i=l ; i<=r ; i++)
#define rrep(i,l,r) for(i=r ; i>=l ; i--)
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
#define prdb(x) cout << fixed << setprecision(10) << x
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll expo (ll x, ll y) {ll res = 1; while (y) {if (y & 1)res = res * x; res %= MOD; y = y >> 1; x = x * x; x %= MOD;} return res;}
ll minn(ll a,ll b) {return (a>b)?b:a;}
ll maxx(ll a,ll b) {return (a>b)?a:b;}
ll smod(ll a,ll md=MOD) {a=a%md; if(a<0)a+=md; return a;}
ll nCk(ll n, ll k) { ll res = 1; if (k > n - k)k = n - k; for (ll i = 0; i < k; ++i) { res *= (n - i); res /= (i + 1); }return res;} 

int n;
const int N = 1000;
vector<int> gset;
vector<int> used;
vector<int> chosen;
set<vector<int>> final;
void find(int sum){
      if(sum== 0 ){
            vector<int> temp = chosen;
            sort(all(temp));
            final.insert(temp);
      }
      int i;
      rep(i,0,n-1){
            if(sum>=gset[i]&&used[i]==0){
                  chosen.pb(gset[i]);
                  used[i]= 1;
                  find(sum- gset[i]);
                  used[i] = 0;
                  chosen.pop_back();
            }
      }
}
void solve() 
{
      gset = {10, 7, 5, 18, 12, 20, 15};
      // gset= {15, 22, 14, 26, 32, 9, 16, 8};
      n = gset.size();
      used.resize(gset.size(),0);
      int sum = 35;
      find(sum);
      for(auto a: final){
            for(auto b: a){
                  cout<<b<<' ';
            }
            cout<<"\n";
      }
}

int main() 
{
      #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin); 
            freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr), cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--) {
      solve();
      }
      return 0;
}