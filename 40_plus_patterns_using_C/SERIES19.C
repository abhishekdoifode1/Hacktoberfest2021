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
  for(j=1;j<=i;j++)
  {
   printf("%d",j);
  }
  printf("\n");
 }
 getch();
}