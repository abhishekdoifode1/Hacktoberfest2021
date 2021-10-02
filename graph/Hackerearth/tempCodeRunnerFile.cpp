#include <bits/stdc++.h>

using namespace std;

// string sub_str()
int palindrome_check(string s,int n)
{
    int flag=1;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        flag=0;
    }
    return flag;
}
int main()
{
    int n;
    cin>>n;
    int count=n;
    string s,r;
    cin>>s;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            r=s.substr(j,j+i-1);
            cout<<r<<endl;
            if(palindrome_check(r,i))
            {
                count++;
                cout<<r<<" "<<count<<endl;
            }
        }
    }
    // string r=s.substr(1,3);
    cout<<count;
}