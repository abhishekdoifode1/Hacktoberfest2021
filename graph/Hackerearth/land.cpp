#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int h=0;h<t;h++)
    {
    int m,n,sum=0,min,sum1=0;
    cin>>m>>n;
    int s[m][n];
    for(int i=0;i<m;i++)
    {
    for(int j=0;j<n;j++)
    {
        cin>>s[i][j];
        sum1+=s[i][j];
        // min=sum;
    }
    }
    cout<<sum1<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            // sum1=sum;

            if((s[i][j]>s[i-1][j]) && i>=1)
            {
                sum1=sum1-s[i-1][j];
                s[i-1][j]=0;
            }

            if((s[i][j]>s[i+1][j]) && i<m-1 )
            {
                sum1=sum1-s[i+1][j];
                s[i+1][j]=0;
            }

            if(s[i][j]>s[i][j-1] && j>=1)
            {
                sum1=sum1-s[i][j-1];
                s[i][j-1]=0;
            }

            if(s[i][j]>s[i][j+1] && j<n-1)
            {
                sum1=sum1-s[i][j+1];
                s[i][j+1]=0;
            }

            if((s[i][j]>s[i-1][j-1]) && i>=1 && j>=1)
            {
                sum1=sum1-s[i-1][j-1];
                s[i-1][j-1]=0;
            }

            if((s[i][j]>s[i+1][j+1]) && i<m-1 && j<n-1)
            {
                sum1=sum1-s[i+1][j+1];
                s[i+1][j+1]=0;
            }

            if(s[i][j]>s[i+1][j-1] && i<m-1 && j>=1)
            {
                sum1=sum1-s[i+1][j-1];
                s[i+1][j-1]=0;
            }

            if(s[i][j]>s[i-1][j+1] && i>=1 && j<n-1)
            {
                sum1=sum1-s[i-1][j+1];
                s[i-1][j+1]=0;
            }

            // sum1-=s[i][j];
            // if(min>sum1)
            // min=sum1;
            cout<<i<<" "<<" "<<j<<" "<<sum1<<endl;

        }
    }
    cout<<sum1<<endl;
    }
}