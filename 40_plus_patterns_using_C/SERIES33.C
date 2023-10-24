#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,n;
 printf("Enter the number of rows\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=(2*n)+3;j++)
  {
   if((j>=i&&j<=i+2)||(j<=(2*n)+4-i&&j>=(2*n)+2-i)||(j==n+2&&i==n-1))
   printf("*");
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
}
