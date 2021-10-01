/* Problem - Lauren has a chart of distinct projected prices for a house over the next several years. She must buy the house in one year and sell it in another, and she must do so at a loss. She wants to minimize her financial loss.
   
   Input Format
      The first line contains an integer n, the number of years of house data.
      The second line contains n space-separated long integers that describe each price[i]. */


#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int n;
ll a[200200];

int main() {
    scanf("%d", &n);
    FOR(i,n) scanf("%lld", &a[i]);
    set<ll> s;
    long long res = 1000000000000000000LL;
    FOR(i,n) {
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) {
            res = min(res, *it-a[i]);
        }
        s.insert(a[i]);
    }
    printf("%lld\n", res);
    return 0;
}
