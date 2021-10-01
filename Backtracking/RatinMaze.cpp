/*
Problem Statement:
      A Maze is given as N*N binary matrix of blocks where source block is the 
      upper left most block i.e., maze[0][0] and destination block is lower 
      rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to 
      reach the destination. The rat can move only in two directions: forward 
      and down. In the maze matrix, 0 means the block is a dead end and 1 means 
      the block can be used in the path from source to destination.

      Time complexity = O(2^(n^2)). 
      Space complexity = O(n^2).
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
// int mat[N][N];
vector<vector<int> > mat;
vector<vector<int> > solmat;

void printsolmat(){
      int i,j;
      rep(i,0,n-1){
            rep(j,0,n-1){
                  cout<< solmat[i][j]<<' ';
            }cout<<'\n';
      }
}
void findpath(int x,int y){
      if(x==n-1&&y==n-1){
            printsolmat();
            exit(0);
      }
      // moving left
      if(y+1<n&&mat[x][y+1]==1){
            solmat[x][y+1]=1;
            findpath(x,y+1);
            solmat[x][y+1]=0;
      }
      // moving right
      else if(x+1<n&&mat[x+1][y]==1){
            solmat[x+1][y]=1;
            findpath(x+1,y);
            solmat[x+1][y]=0;
      }
}
void solve() {
      n=4;
      mat = {{1, 0, 0, 0},
                  {1, 1, 0, 1},
                  {0, 1, 0, 0},
                  {1, 1, 1, 1}};
      solmat.resize(n,vector<int>(n,0));
      solmat[0][0]=1;
      findpath(0,0);
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