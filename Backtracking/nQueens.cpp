/*
Problem Statement:
      The N Queen is the problem of placing N chess queens on an N×N chessboard 
      so that no two queens attack each other. For example, following is a solution
      for 4 Queen problem.
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

// To store all not Visitable.
vector <int> maindiag;
vector <int> crossdiag;
vector <int> rows;
vector <int> cols;

vector<int> ans; 

void printans(){
      int i,j;
      rep(i,0,n-1){
            rep(j,0,ans[i]-1){
                  cout<<"0 ";
            }
            cout<<"1 ";
            rep(j,ans[i]+1,n-1){
                  cout<<"0 ";
            }
            cout<<"\n";
      }
}

void findpos(int x){
      if(x==n){
            printans();
            exit(0);
      }
      int j;
      rep(j,0,n-1){
            if(maindiag[x-j]==0&&crossdiag[x+j]==0&&cols[j]==0){
                  maindiag[x-j]= 1;
                  crossdiag[x+j]=1;
                  cols[j]= 1;
                  ans.pb(j);
                  findpos(x+1);
                  ans.pop_back();
                  maindiag[x-j]= 0;
                  crossdiag[x+j]=0;
                  cols[j]= 0;
            }
      }
}
void solve() {
      n=8;
      maindiag.resize(n,0);
      crossdiag.resize(n,0);
      rows.resize(n,0);
      cols.resize(n,0);
      findpos(0);
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