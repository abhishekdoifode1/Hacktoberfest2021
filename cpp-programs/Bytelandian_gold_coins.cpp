//bytelandian gold coins
#include<bits/stdc++.h>
using namespace std;

long long int calculate(vector<long long int> &dp, long long int n)
{
    if(n<10)
        return n;

    if(n<1000000)
    {
        if(dp[n])
            return dp[n];

        else
        {
            //now, calculate
            long long int x=calculate(dp, n/2)+calculate(dp, n/3)+calculate(dp, n/4);
            dp[n]=max(n,x);

            return dp[n];
        }
    }

    long long int x=calculate(dp, n/2)+calculate(dp, n/3)+calculate(dp, n/4);

    return max(n,x);
}

int main()
{
    long long int i,j,k,n;
    long long int x,y,z;
    int t;

    vector<long long int> dp(1000000,0);

    cout<<"Enter the amount of bytelandian coin you have ?"<<endl;
    cin>>n;
    cout<<"Maximum amount of american dollars you can make from this is "<<endl;
    cout<<calculate(dp,n)<<endl;

    return 0;
}
© 2021 GitHub, Inc.
Terms
