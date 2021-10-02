#include<bits/stdc++.h>
using namespace std;


bool dfscheck(vector<int> adj[],int s,vector<int> &vis, vector<int> &dfsvis)
{
    vis[s]=1;
    dfsvis[s]=1;

    for(auto it: adj[s])
    {
        if(vis[it]==0)
        {
            if(dfscheck(adj,it,vis,dfsvis))
                return true;
        }
        else if(dfsvis[it]==1)
            return true;
    }
    dfsvis[s]=0;
    return false;
}


bool check(vector<int> adj[],int v)
{
    vector<int> visited(v,0);
    vector<int> dfsvis(v,0);

    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            if(dfscheck(adj,i,visited,dfsvis))
                return true;
        }
    }
    return false;
}


int main()
{
    int v;
    cin>>v;

    int e;
    cin>>e;

    vector<int> adj[v];

    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;

        adj[s].push_back(d);
    }

    bool ans=check(adj,v);

    if(ans)
        cout<<"cycle";
    else
        cout<<"no cycle";

    return 0;
}
