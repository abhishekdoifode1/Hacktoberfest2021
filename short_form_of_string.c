#include<stdio.h>
#include<conio.h>

void main()
{
	char str[80],c,ss[10];
	int i,j,in=0;
	clrscr();
	printf("Enter a string : ");
	gets(str);
	for(i=0,j=0;(c=str[i])!='\0';i++)
	{
		if(c<'A' || c>'Z'&&c<'a' || c>'z') in=0;
		else if(!in)
		{
			in=1;
			ss[j++]=c;
		}
	}
	ss[j]='\0';
	printf("\nShort form is %s",ss);
	getch();
}
