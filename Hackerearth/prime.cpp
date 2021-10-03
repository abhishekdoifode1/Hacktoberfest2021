#include <iostream>
using namespace std;
int main()
{
    int n,c=0;
    cin>>n;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        c++;
    }
    cout<<c;
}