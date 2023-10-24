#include<stdio.h>
#include<conio.h>
main()
{
	int i[3][3],j,k;
	for(j=0;j<3;j++)
	{
		for(k=0;k<3;k++)
		{
			printf("enter no.[%d][%d]:",j,k);
			scanf("%d",&i[j][k]);
		}
	}
	
	for(j=0;j<3;j++)
	{
		for(k=0;k<3;k++)
		{
			printf("%d",i[j][k]);
		}
		printf("\n");
		
	}
	
	
	for(j=0;j<3;j++)
	{
		printf("\n");
		for(k=0;k<3;k++)
		    if(j>k)
		    printf("%d",0);
		    else
		    printf("%d",i[j][k]);
	}
	printf("\n\n");
}
