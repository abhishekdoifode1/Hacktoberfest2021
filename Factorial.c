#include<stdio.h>
#include<conio.h>
void main()
{
int fact = 1,n;
printf("Enter the number");
scanf("%d",&n); 
if(n==0)
{
return 1;
}
else{
for(i=1;i<=n;i++)
{
fact=fact*i;
}
printf("Factorial of %d is %d",n,fact);
}
getch();
}
