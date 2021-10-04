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
   if(j<=i||j>=(2*n)-i)
   printf("*");
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
 clrscr();
}