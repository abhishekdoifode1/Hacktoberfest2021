#include<bits/stdc++.h>
using namespace std;

#define END '\n'
#define int long long

struct node{
	int m, c;
	node(){
		m = 2e9;
		c = 0;
	}
};
struct SegTree{
	int size;
	vector<node> f;
	node init;
	void initialize(int n){
		size = 1;
		while(size < n)
			size *= 2;
		f.assign(2 * size, init);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			f[x].m = v;
			f[x].c = 1;
			return;
		}
		int m = (lx + rx)/2;
		if(i < m)
			set(i, v, 2 * x + 1, lx, m);
		else
			set(i, v, 2 * x + 2, m, rx);
		//f[x] = min(f[2 * x + 1], f[2 * x + 2]);
		if(f[2 * x + 1].m < f[2 * x + 2].m){
			f[x] = f[2 * x + 1];
		}
		else if(f[2 * x + 1].m > f[2 * x + 2].m){
			f[x] = f[2 * x + 2];
		}
		else{
			f[x].m = f[2 * x + 1].m;
			f[x].c = f[2 * x + 1].c + f[2 * x + 2].c;
		}

	}
	void set(int i, int v){
		set(i, v, 0, 0, size);
	}
	node mn(int l, int r, int x, int lx, int rx){
		if(lx >= r|| l >= rx) return init;
		else if(lx >= l && rx <= r) return f[x];
		int m = (lx + rx)/2;
		node A = mn(l, r, 2 * x + 1, lx, m);
		node B = mn(l, r, 2 * x + 2, m, rx);
		node C = init;
		if(A.m < B.m)
			C = A;
		else if(A.m == B.m){
			C.m = A.m;
			C.c = A.c + B.c;
		}
		else
			C = B;
		return C;
	}
	node mn(int l, int r){
		return mn(l, r, 0, 0, size);
	}
};
void solve(){
	int n, m;
	cin>>n>>m;
	SegTree st;
	st.initialize(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		st.set(i, a[i]);
	}
	for(int j = 0; j < m; j++){
		int type;
		cin>>type;
		if(type == 1){
			int i, v;
			cin>>i>>v;
			st.set(i, v);
		}
		else{
			int l, r;
			cin>>l>>r;
			node ans = st.mn(l, r);
			cout<<ans.m<<" "<<ans.c<<END;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}
