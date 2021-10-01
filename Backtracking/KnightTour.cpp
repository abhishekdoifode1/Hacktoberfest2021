/*
Problem Statement : 
      Given a N*N board with the Knight placed on the first block of an empty board. 
      Moving according to the rules of chess knight must visit each square exactly 
      once. Print the order of each the cell in which they are visited.
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
vector<pair<int,int>> moves = {{2,1},{2,-1},{1,2},{-1,2},{-2,1},{-2,-1},{1,-2},{-1,-2}};
const int N = 1000;
int mat[N][N];

void printsol(){
      int i,j;
      rep(i,0,n-1){
            rep(j,0,n-1){
                  cout<<mat[i][j]<<' ';
            }
            cout<<"\n";
      }
      cout << "-------------\n";
}
void nextMove(int x,int y,int moveno){
      if(moveno==n*n){
            printsol();
            // exit(0);
      }
      for(auto add: moves){
            if((x+add.f)<n&&(x+add.f)>=0&&(y+add.se)<n&&(y+add.se)>=0){
                  if(mat[x+add.f][y+add.se]==-1){
                        mat[x+add.f][y+add.se]= moveno;
                        nextMove(x+add.f,y+add.se,moveno+1);
                        mat[x+add.f][y+add.se]=-1;
                  }
            }
      }
}

void solve() {
      // cin>>n;  // n can be upto 6
      n = 5;
      ms(mat,-1,sizeof(mat));
      mat[0][0]=0;
      nextMove(0,0,1);

}

int main() 
{
      // #ifndef ONLINE_JUDGE
      //       freopen("input.txt", "r", stdin); 
      //       freopen("output.txt", "w", stdout);
      // #endif
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr), cout.tie(nullptr);


      int t = 1;
      // cin >> t;
      while(t--) {
            solve();
      }
      return 0;
}