#include<stdio.h>
int main()
{
	int n,i,l,temp=0;
	printf("Enter size of array :\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array is  :\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
//	a[0]=-999;
	for(i=1;i<=n-1;i++)
	{
		temp=i;
		while(temp>0 && a[temp-1]>a[temp])
		{	l=a[temp];
		a[temp]=a[temp-1];
		a[temp-1]=l;temp--;}
	}
	printf("Array is ascending order :\n");
	for(i=0;i<=n-1;i++)
	printf("%d ",a[i]);
	return 0;
}
