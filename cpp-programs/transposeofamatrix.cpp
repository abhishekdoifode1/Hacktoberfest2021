#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int main()
{
    int a[10][10],transpose[10][10],row,column,i,j;
    cout<<"enter the number of rows and columns:";
    cin>>row>>column;
    cout<<"\nenter the rows and columns of matrix:" <<endl;
for(i=0; i<row; ++i)
{
    for(j=0;j<column;++j)
    {
        cout<< " enter element a" <<i+1<<j+1<<":";
        cin>>a[i][j];
    }
}
cout<<"entered matrix:" <<endl;
for(int i=0; i<row; ++i)
{
    for(j=0;j<column;++j)
    {
      cout<< " "<<a[i][j];
      if(j==column-1)
      cout<<endl<<endl;
    }
}
for(i=0;i<row;++i)
{
    for(j=0;j<column;++j)
    {
    transpose[j][i]= a[i][j];
    }
}
cout<<"transpoe of matrix:";
for( i=0;i<row;++i)
{
for(j=0;j<column;++j)
{
    cout<< " "<<transpose[i][j];
    if(j == row-1)
    cout<< endl <<endl;
}
}
return 0;
}