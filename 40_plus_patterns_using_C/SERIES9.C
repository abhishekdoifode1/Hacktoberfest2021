#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i,j,n;
 printf("enter the number of rows \n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=(2*n)-1;j++)
  {
   if(j==n+1-i||j==n-1+i)
   printf("*");
   else
   printf(" ");
  }
  printf("\n");
 }
 for(i=1;i<=n-1;i++)
 {
  for(j=1;j<=(2*n)-1;j++)
  {
   if(j==1+i||j==(2*n)-1-i)
   printf("*");
   else printf(" ");
  }
  printf("\n");
 }
 getch();
}
