#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<s.length();j++)
        if(s[i]==s[j] && i!=j && i<j)
        {
          count++;
          s.replace(i,1,"1");
        }
    }
    cout<<count<<endl<<s.length()<<endl<<s;
    return 0;
}