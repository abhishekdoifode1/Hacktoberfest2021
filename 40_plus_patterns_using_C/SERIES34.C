#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,k=1,n;
 printf("enter the number of rows\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=i;j++)
  {
   if(j==1||i==j)
   {
    if(k%2==1)
    printf("1");
    else
    printf("0");
   }
   else printf("*");
    k++;
  }
  printf("\n");
 }
 getch();
}