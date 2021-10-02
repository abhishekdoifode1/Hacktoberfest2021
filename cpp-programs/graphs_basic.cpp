#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void bfs(vector<vector<int> > v, int sv) {
	unordered_map<int, int> visited;
	queue<int> q;
	q.push(sv);
	while(q.size()>0) {
		int f = q.front();
		q.pop();
		cout<<f<<" ";
		visited[f]++;
		int n = v.size();
		for(int i=0; i<n; i++) {
			if(v[f][i]==1 && visited[i]==0) {
				q.push(i);
				visited[i]++;
			}
		}
	}
}

void dfs(vector<vector<int> > matrix, int sv, unordered_map<int, int> &visited) {
	
	cout<<sv<<" ";
	visited[sv]++;
	int n = matrix.size();
	for(int i=0; i<n; i++) {
		if(matrix[sv][i]==1 && visited[i]==0) {
			dfs(matrix, i, visited);
		}
	}
}

int main() {
	int n, e;
	cin>>n;
	cin>>e;
	
	vector<vector<int> > matrix(n,vector<int>(n,0));
	
	for(int i=0;i<e;i++) {
		int fv,sv;
		cin>>fv>>sv;
		matrix[fv][sv] = 1;
		matrix[sv][fv] = 1;
	}
	
	int sv;
	cin>>sv;
	unordered_map<int, int> visited;
	bfs(matrix, sv);
	
}
