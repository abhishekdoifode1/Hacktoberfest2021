#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,k,n;
 clrscr();
 printf("Enter number of rows\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  k=1;
  for(j=1;j<=(2*i)-1;j++)
  {
  if(j<i){
  printf("%d",k);
  k=k+2;}
  else{
  printf("%d",k);
  k=k-2;}
  }
  printf("\n");
 }
 getch();
}