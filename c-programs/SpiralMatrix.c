#include <stdlib.h>
#include <stdio.h>
int main()
{
int n,m;
printf(“\nInput the number of rows : “);
scanf(“%d”,&m);
printf(“\nInput the number of columns : “);
scanf(“%d”,&n);
int arr[m][n];
int i,j;
printf(“\nInput the matrix \n”);
for(i = 0; i < m; i++)
{
for(j = 0; j < n; j++)
{
scanf(“%d”,&arr[i][j]);
}
}
printf(“\nThe Matrix is \n”);
for(i = 0; i < m; i++)
{
for(j = 0; j < n; j++)
{
printf(“%d “,arr[i][j]);
}
printf(“\n”);
}
printf(“\nSpiral Matrix : “);
int k = 0, l = 0;
while(k < m && l < n)
{
for(i = l; i < n; i++)
{
printf(“%d “,arr[k][i]);
}
k++;
for(i = k; i < m; i++)
{
printf(“%d “,arr[i][n-1]);
}
n–;
if(k < m)
{
for(i = n – 1; i >= 0; –i)
{
printf(“%d “,arr[m-1][i]);
}
m–;
}
if(l < n)
{
for(i = m – 1; i >= k; i–)
{
printf(“%d “,arr[i][l]);
}
l++;
}
}
return 0;
}

