#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i,j,n;
 clrscr();
 printf("enter the number of rows \n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(j>=n+1-i)
   printf("%d ",i);
   else
   printf(" ");
  }
  printf("\n");
 }
 for(i=1;i<=n-1;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(j>=1+i)
   printf("%d ",(n-i));
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
}