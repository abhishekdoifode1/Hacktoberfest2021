#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    short int t,j;
    string s;
    int i;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>s;
        int W=0;
        // cout<<s.length()<<endl;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='B')
            {

                if(s[i-1]=='W' && i-1>=0)
                {
                    if(s[i-3]!='B' && s[i-2]!='B' && s[i+1]!='B')
                    W++;
                }
                if(s[i-2]=='W' && i-2>=0)
                {
                    if(s[i-4]!='B' && s[i-3]!='B' )
                    W++;
                }
                 if(s[i+1]=='W'  && s[i-1]!='B' && i+1<=s.length())
                W++;
                 if(s[i+2]=='W' && i+1<=s.length())
                W++;
            }
        }
    cout<<W<<endl;
    }
    return 0;
}