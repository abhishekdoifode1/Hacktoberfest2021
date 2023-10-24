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
   if(j==i-2||j==i+2||j==n-1-i||j==n+3-i)
   printf("*");
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
 clrscr();
}