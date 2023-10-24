#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j;
 clrscr();
 for(i=1;i<=4;i++)
 {
  for(j=1;j<=9;j++)
  {
   if((j==6-i)||(j==7-i)||(j==8-i&&i<4)||(j==9-i&&i<3)||(j==9&&i==1))
   printf("*");
   else
   printf(" ");
  }
  printf("\n");
 }
 for(i=1;i<=5;i++)
 {
  for(j=1;j<=9;j++)
  {
   if((j==i)||(j==i+1&&i>1)||(j==2+i&&i>2)||(j==3+i&&i>3)||(j==9&&i==5))
   printf("*");
   else
   printf(" ");
  }
  printf("\n");
 }
 getch();
}