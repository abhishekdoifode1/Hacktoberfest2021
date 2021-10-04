#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,n,k,m;
 clrscr();
 printf("Enter the number of rows\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  k=i-1;
  m=i;
  for(j=1;j<=n;j++)
  {
   if(j<=n+1-i)
   printf("%d",m++);
   else
   printf("%d",k--);
  }
  printf("\n");
 }
 getch();
}