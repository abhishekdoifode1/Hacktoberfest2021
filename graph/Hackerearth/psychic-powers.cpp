#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length()-5;i++)
    {
        count=0;
        for(int j=i;j<=i+5;j++)
        
        if(s[i]==s[j])
        count++;

        if(count==6)
        break;
    }

    if(count>=6)
    cout<<"Sorry, sorry!";
    else 
    cout<<"Good luck!";
    return 0;
}