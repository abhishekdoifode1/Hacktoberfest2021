class Solution {
   
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long mod=1000000007;
        vector<pair<long long,long long>>adj[n+5];
        for(long long i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }
        long long dist[1000];
        long long path[1000];
        long long vis[1000];
        for(long long i=0;i<1000;i++)dist[i]=LLONG_MAX,path[i]=0,vis[i]=0;
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long> > >pq;
        pq.push({0,0});
        dist[0]=0;
        path[0]=1;
        
        while(!pq.empty())
        {
            
            pair<long long,long long>temp;
            temp=pq.top();
            pq.pop();
            if(temp.first==LLONG_MAX)   continue;
              if(vis[temp.second])  continue;
              vis[temp.second]=1;
            for(auto i:adj[temp.second])
            {
                // cout<<'u';
                if(dist[i.second]==LLONG_MAX || dist[i.second]>dist[temp.second]+i.first)
                {
                    pq.push({(temp.first+i.first),i.second});
                    dist[i.second]=dist[temp.second]+i.first;
                    path[i.second]=path[temp.second];
                }
                else if(dist[i.second]==dist[temp.second]+i.first)
                {
                    path[i.second]=(path[i.second]+path[temp.second])%mod;
                }
                
            }
            // cout<<pq.size()<<'\n';
        }
        return path[n-1];
    }
};