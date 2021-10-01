// C++ implementation of Minimum spanning tree using Kruskal's algorithm
// Run time complexity = O(ElogE)

// Template for code
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define piii pair<ll,pair<ll,ll>> 
#define pii pair<ll,ll>
#define pb push_back
#define INF 0x3f3f3f3f
int n;

// vector to store {cost, {vertex1, vertex2}} in the pair of pair<int,pair<int,int>>
vector<piii> edges;
// vector to denote the parent, rank(height) for each node  
vector<pii> parent ((int)1e4+5); 
// vector to store the adjacency list
vector<pii> g[(int)1e4+5];

// Finding the parent of a node x using path compressions
ll find(ll x)
{
	// parent[x].first deontes the parent of x
	// parent[x].second denotes the rank of x
	if(parent[x].first==x)
		return x;
	return parent[x].first=find(parent[x].first);
}

// Union by rank(height) compression used
// Union based on the fact that both x and y are present in different sets,
// condition already checked in main line 60
void merge(ll x, ll y)
{
	ll set_x=find(x);				
	ll set_y=find(y);
	// If the rank of x is smaller than y, merge x in y
	if(parent[set_x].second<parent[set_y].second)
		parent[set_x].first=set_y;
	// If the rank of y is smaller than x, merge y in x
	else if(parent[set_x].second>parent[set_y].second)
		parent[set_y].first=set_x;
	// The rank of both x and y are equal, merge one into the other
	// Here, y is merged into x and it's rank is increased by 1
	// Consider the case,
	//     1		4
	//    / \	   / \
	//   2   3    5   6
	// If we wish to union 3 and 6, union by rank (height), rank(3) = rank(6) = 1 results in
	//     1	
	//    / \ \  
	//   2   3 4   
	//        / \
	//       5   6
	// finally, rank(1) = 2, increased by 1 
 	else
	{
		parent[set_y].first=set_x;
		parent[set_x].second++;
	}
}

ll MST(ll start)
{
	ll cnt=0,sum=0,u,v,w,x,y;
	for(auto it: edges)
	{
		w=it.first;
		u=it.second.first;
		v=it.second.second;
		x=find(u);
		y=find(v);
		// If parent of x is not same as the parent of y, merge them
		// and add this edge
		// Kruskal’s is a greedy algorithm, the added edge has the least weight 
		// amongst all the remaining edges
		if(x!=y)
		{
			sum+=w;
			merge(u,v);
			cnt++;
		}
		// If the number of edges included is equal to nodes - 1, 
		// it means that we have formed the MST, do not add any more edges
		if(cnt==n-1)
			break;
	}
	return sum;
}

int main()
{
	fast;
	ll m,u,v,w;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edges.pb({w,{u,v}});
		g[u].pb(pii(v,w));
		g[v].pb(pii(u,w));
	}
	// Sorting the edges by their weight
	sort(edges.begin(),edges.end());
	for(int i=1;i<=n;i++)
	{
		// Initially, each node is its own parent
		parent[i].first=i;
		// Initially, the rank of each node = 0
		parent[i].second=0;
	}
	// Any valid node can be used as the starting point as 
	// each node has to be added in the MST
	cout<<MST(0);
	return 0;
}


