/* C++ Program - Print Floyd's Triangle */
		
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int range, i, j, k=1;
	cout<<"Enter the range (upto how many line ?) : ";
	cin>>range;
	cout<<"\nFloyd's Triangle :\n";
	for(i=1; i<=range; i++)
	{
		for(j=1; j<=i; j++, k++)
		{
			cout<<k<<" ";
		}
		cout<<"\n";
	}
	getch();
}
