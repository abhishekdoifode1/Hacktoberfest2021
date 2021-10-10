#include<stdio.h>

int max(int a,int b);

int v[20][20];

int main()
{
	int i,j,p[20],w[20],n,total;
	printf("Enter the number of items\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the weight and profit of the item %d:\n",i);
		scanf("%d %d",&w[i],&p[i]);
	}
	printf("Enter the capacity of the knapsack:\n");
	scanf("%d",&total);
	for(i=0;i<=n;i++)
	    v[i][0]=0;
	for(j=0;j<=total;j++)
    	v[0][j]=0;
	for(i=1;i<=n;i++)
    {
	    for(j=1;j<=total;j++)
	    {
		    if(w[i]>j)
		        v[i][j]=v[i-1][j];
		    else
		        v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
	    }
    }
	printf("\nThe maximum profit is %d",v[n][total]);
	printf("\nThe items selected are:");
	j=total;
    for(i=n;i>=1;i--)
		if(v[i][j]!=v[i-1][j])
		{
			printf("\titem %d ",i);
			j=j-w[i];
		}
    return 0;
}

int max(int a,int b)
{
 	return(a>b)?a:b;
}