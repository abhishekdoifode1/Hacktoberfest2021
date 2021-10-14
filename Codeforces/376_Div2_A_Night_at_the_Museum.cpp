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
#define pi 3.141592653589793238
#include<time.h>
#include<sstream>
using namespace std;

void sol(){
    
    string str ; cin >> str;
    ll len = str.length(),steps,cur,req(0),total(0);
    for_i(len){
        cur = req;
        req = str[i]-'a';
        ll temp = req-cur;
        if(temp<0)
        temp*=-1;
        steps = min(temp,26-temp);
        total+=steps;
        
        
    }
    cout<<total <<"\n";

}
 
 
int main(){
    fast
 
    ll tc= 1;
    //cin >> tc;
    while(tc--){
        sol();
    }
 
}
 