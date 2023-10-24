#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,n;
 clrscr();
 printf("enter number of rows\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  char m=n-1;  
  char k=64+i;
  for(j=1;j<=i;j++)
  {
  printf("%c ",k);
  k=k+m;
  m--;
  }
  printf("\n");
 }
 getch();
}
