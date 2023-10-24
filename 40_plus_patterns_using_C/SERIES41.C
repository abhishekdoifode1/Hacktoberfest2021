#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i,j,k=0,n;
 clrscr();
 printf("Enter number of rows\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=pow(2,i-1);j++&&k++)
  {
   int m=k%9;
   printf("%d",++m);
  }
  printf("\n");
 }
 getch();
}