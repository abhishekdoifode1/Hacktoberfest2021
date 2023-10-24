#include <bits/stdc++.h>

using namespace std;

// string sub_str()
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    int l,x,count=0;
    cin>>l;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            x=i;
            if(x==l-1)
            count+=1;
            else
            count+=(x+1)*(l-x);
        }
    }
    cout<<count<<endl;
    }
}