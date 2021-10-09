#include<iostream>
using namespace std;
int matrix[1000][1000];
int min_dis(int dist[], int visited[], int V, int source){
	int min=100; //INT_MAX
	int index=0;
	for(int i=0; i<V; i++){
		if(min>dist[i] && visited[i]!=1 && dist[i]!=-1 && i!=source){
			min=dist[i];
			index=i;
		}
	}
	visited[index]=1;
	return index;
}
void shortest_path(int V, int E, int source){
	int dist[V];
	int visited[V];

	for(int i=0; i<V; i++){
		dist[i]=matrix[source][i];
	}
	for(int i=0; i<V; i++){
		visited[i]=0;
	}
	visited[source]=1;
	
	for(int j=0; j<V-2; j++){
		int min_dist_index=min_dis(dist, visited, V, source);
		for(int i=0; i<V; i++){
			if(visited[i]!=1 && matrix[min_dist_index][i]!=-1){
				if(dist[i]==-1 or dist[i]>matrix[min_dist_index][i]+dist[min_dist_index]){
					dist[i]=matrix[min_dist_index][i]+dist[min_dist_index];
				}
			}
		}
	}
	cout<<"\nDISTANCE : ";
	for(int i=0; i<V; i++){
		cout<<dist[i]<<" ";
	}
	
}
int main()
{
	int V,E,source;
	cout<<"Enter no. of vertices : ";
	cin>>V;
	cout<<"Enter no. of edges : ";
	cin>>E;
	cout<<"Enter source : ";
	cin>>source;

	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			if(i==j)
				matrix[i][j]=0;
			else
				matrix[i][j]=-1;
		}
	}
	
	int u,v,wt;
	for(int i=0;i<E;i++){
        cin>>u>>v>>wt;
		matrix[u][v]=wt;
	}
    cout<<endl;
	shortest_path(V, E, source);
    cout<<endl;

}