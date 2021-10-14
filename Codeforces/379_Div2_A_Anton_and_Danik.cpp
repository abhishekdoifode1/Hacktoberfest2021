#include<bits/stdc++.h>
#define ll long long
#define p_pair(a,b) push_back({a,b})
#define vec2d(arr, n , m) vector< vector<ll> > arr( n , vector<ll> (m));
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define maxsize 200001
#define atg aman the great
#define max3(a,b,c) max(max(a,b), c)
#define min3(a,b,c) min (min(a,b), c)
#define mod 1000000007
#define INF INT_MAX
#define for_i(n) for( long long i=0; i<n; i++)
#define for_j(n) for(long long j=0; j<n; j++)
#define for_1(n) for(long long i = 1; i<=n; i++)
#define ifDiv(n,i) if(n%i==0)
#define pi 3.141592653589793238
#include<time.h>
using namespace std;




 void sol(){
    ll n; cin >> n;
    ll a(0),d(0);
    char s;
    for_i(n){
    cin >> s;
          if(s=='A')a++;
        else d++;
    }
    if(a>d)cout<<"Anton";
    else if(d>a) cout<< "Danik";
    else cout<< "Friendship";
    cout<<"\n";
 }

int main(){
    fast
    ll tc= 1;
    //cin >> tc;

    while(tc--){
        sol();
    }

}

