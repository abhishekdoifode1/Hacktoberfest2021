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
  for(j=1;j<=n;j++)
  {
   if(j==i||j==n+1-i)
   printf("* ");
   else if(j==1|j==n||i==1||i==n)
   printf("* ");
   else
   printf("  ");
  }
  printf("\n");
 }
 getch();
 clrscr();
}