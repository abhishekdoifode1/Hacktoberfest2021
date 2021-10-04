#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i,j,n,k;
 clrscr();
 printf("enter the number of rows \n");
 scanf("%d",&n);
 k=1;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(j>=n+1-i)
   printf("%d ",k++);
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
}