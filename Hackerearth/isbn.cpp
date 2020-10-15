#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;

    cin>>s;
    int sum=0,i;
    if(s.length()!=10)
    cout<<"Illegal ISBN";
    else
    {
        for(i=0;i<s.length();i++)
        {
            sum+= (i+1)*(s.at(i));
        }
        if(sum%11==0)
        cout<<"Legal ISBN";
        else
        {
            cout<<"Illegal ISBN";
        }
        
    }
    
return 0;
}