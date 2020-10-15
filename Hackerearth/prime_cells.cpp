#include <iostream>
using namespace std;

// int checktop(int i,int j);
// int checkright(int i,int j);
// int checkleft(int i,int j);
// int checkbottom(int i,int j);

int main()
{
    short int n,i,j,cells,count=0;
    cin>>n;
    short int g[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   cells=0;
            //for g[i][j]
            // its top     g[i-1][j]
            // its left    g[i][j-1]
            // its right   g[i][j+1]
            // its bottom  g[i+1][j]
            if(i-1>=0 && j>=0)
            cells+=g[i-1][j];
             if(i>=0 && j-1>=0)
            cells+=g[i][j-1];
             if(i>=0 && j+1>=0 && j+1<n)
            cells+=g[i][j+1];
             if(i+1>=0 && j>=0 && i+1<n)
            cells+=g[i+1][j];
         
            if(cells%2!=0)
        
            {
            
            count++;
            }
            // cout<<count<<endl;
        }
       
    }
     cout<<count<<endl;
    return 0;
}




        