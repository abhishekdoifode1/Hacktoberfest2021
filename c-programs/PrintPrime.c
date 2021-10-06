#include<stdio.h>
int main()
{

//This program prints all prime numbers between firstNum and lastNum

	int firstNum,lastNum,i,j;
	printf("Enter first no:");
	scanf("%d",&firstNum);
	
	printf("\nEnter last no:");
	scanf("%d",&lastNum);
	
	for(i=firstNum;i<=lastNum;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{break;}
			
		}
	if(i==j)
	{
		printf("%d\n",j);
	}	
	}
}