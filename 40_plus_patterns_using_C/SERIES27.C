#include<stdio.h>
#include<conio.h>
#include<math.h>
int Fact(int y)
{
 int f=1,i;
 for(i=1;i<=y;i++)
  f=f*i;
 return(f);
}
void main()
{
 int i,j,n,k;
 clrscr();
 printf("enter the number of rows \n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   k=(Fact(i-1))/((Fact(n-j))*(Fact(i-n+j-1)));
   if(j>=n+1-i)
   printf("%d ",k);
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
}