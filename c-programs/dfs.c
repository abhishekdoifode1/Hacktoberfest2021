#include<stdio.h>
#include<stdlib.h>

void DFS(int);
int a[10][10],visited[10],n; 

int main()
{
    int i,j;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter adjecency matrix of the graph:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("The nodes reachable are:\n");
    DFS(0);
    for(i =0; i<n; i++)
    { 
	    if(visited[i]==0)
	    {
            printf("\nGraph is not connected");
            exit(0);
        }
    }
    printf("\nGraph is connected");
    return 0;
}

void DFS(int i)
{
    int j;
    printf("%d\t",i);
    visited[i]=1;
    for(j=0;j<n;j++)
    {
        if(!visited[j]&&a[i][j]==1)
            DFS(j);
    }
}