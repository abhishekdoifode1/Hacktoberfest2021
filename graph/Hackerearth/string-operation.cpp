#include <bits/stdc++.h>
using namespace std;

int reverse(string s1,string s2,int a,int b);
int compare(string s1,string s2);

int main()
{
    string S,str1,str,fin1,fin;
    int Q,M,ind;
    int a,b;
    char *ch;
    char cha;
    ch=&cha;
    cin>>S;
    cin>>Q;
    str=S;
    fin1=S;
    fin=S;
    for(int i=1;i<=Q;i++)
    {
        cin>>ind>>cha;
        str1=str1.replace(ind,1,&cha,1); 
    }
    str=str1;
    cin>>M;
    for(int i=1;i<=M;i++)
    {
        cin>>a>>b;
        for(i=a;i<=(a+b)/2;i++)
        {
            str1.replace(i,1,S,a+b-i,1);
            // cout<<str1<<endl;
        }
        for(i=(a+b+2)/2;i<=b;i++)
        {
            fin1.replace(i,1,fin1,a+b-i,1);
            // cout<<stri<<endl;
        }
        fin=fin1;
        reverse(str1,fin1,a,b);
    }
    cout<<str<<endl<<fin<<endl;
    compare(str,fin);
}

int reverse(string s1,string s2,int a,int b)
{
    s1.erase(s1.begin()+(a+b+2)/2,s1.end());
    s2.erase(0,(a+b+2)/2);
    s1.append(s2);
    // cout<<s1;
}

int compare(string s1,string s2)
{
    int count=0;
    for(int i=0;i<s1.length();i++)
    {
    if(s1.compare(i,1,s2,i,1))
    {
    count++;
    }
    }
    cout<<count;
    return 0;
}
