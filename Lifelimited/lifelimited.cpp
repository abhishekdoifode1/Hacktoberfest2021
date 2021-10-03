#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false), cin.tie(NULL)
const int mod = 1e9+7;
//int to string -> to_string()
//string to int -> stoi()

int32_t main()
{
   IOS;
   int t,i,flag=0,j;
   cin>>t;
   while(t--)
   {
   		char s[3][3];
   		for(i=0;i<3;i++)
   		{
   			for(j=0;j<3;j++)
   			{
   				cin>>s[i][j];
   			}
   		}
   		for(i=0;i<2;i++)
   		{
   			for(j=0;j<2;j++)
   			{
   				if(s[i][j]=='l'&&s[i+1][j]=='l'&&s[i+1][j+1]=='l')
   				{	flag=1;break;}
   			else
   				flag=0;
   			}
   			if(flag==1)
   			break;
   		}
   		if(flag==1)
   			cout<<"yes";
   		else
   			cout<<"no";
   		cout<<endl;
   }
   return 0;
}
