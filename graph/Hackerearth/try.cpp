#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n,i,j,p,q;
		int count=0;
		cin>>n;
		int m[n][n];
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				cin>>m[i][j];
			}

		for(p=0;i<n;i++)
		{
			for(q=0;q<n;q++)
			{
				for(int i=0;i<=p;i++)
				{
					for(int j=0;j<=q;j++)
					if(m[i][j]>m[p][q])
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
}