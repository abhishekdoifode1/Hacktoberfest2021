#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n, q; cin >> n >> q;
    int **v = new int*[n];
    for(int j=0;j<n;j++){
        int k; cin >> k;
        v[j] = new int[k];
        for(int i=0;i<k;i++){
            int x; cin >> x;
            v[j][i] = x;
        }
    }
    for(int i=0;i<q;i++){
        int a, b; cin >> a >> b;
        cout << v[a][b]<<endl;
    }
	return 0;

}