#include<stdio.h>
#include<limits.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0}, min, mincost=0, cost[10][10];
void main()
{
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix: \n");
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    {
		    scanf("%d",&cost[i][j]);
		    if(cost[i][j]==0)
			    cost[i][j]=INT_MAX;
	    }
	visited[0]=1;
	printf("\n");
	while(ne<n)
	{
		for(i=0, min=INT_MAX; i<n; i++)
		    for(j=0; j<n; j++)
		        if(cost[i][j]<min)
                    if(visited[i]!=0)
		            {
			            min=cost[i][j];
			            a=u=i;
			            b=v=j;
            		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\nEdge %d [%d %d], Cost = %d",ne++,a+1,b+1,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
	printf("\n\nMinimun Cost = %d ", mincost);
}