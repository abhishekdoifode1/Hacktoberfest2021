#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    vector<string> str,str1;
    cin>>s;
    string st;
    int l=s.length(),flag=0;
   
    int i,i_start,i_end;
    for(i=0;i<l;i++)
    {
       if(s[i]=='/')
        {
            flag++;
            if(s[i-1]=='/')
            flag=0;
            if(s[i+1]!='/' && flag!=0)
            {
                if(flag==1)
                i_start=i+1;
                else
                {
                    flag=1;
                   i_end=i-1;
                   st=s.substr(i_start,i_end-i_start+1);
                    i_start=i+1;

                   str1.push_back(st);
                }
            }
        }
    }
    cout<<str1.size()<<endl;
    for(int i=0;i<str1.size();i++)
    cout<<str1[i]<<endl;
    }
}