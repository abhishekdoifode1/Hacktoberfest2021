#include <iostream>

using namespace std;

string getstring(int d)
{
    if(d==2)
        return "abc";
    if(d==3)
        return "def";
    if(d==4)
        return "ghi";
    if(d==5)
        return "jkl";
    if(d==6)
        return "mno";
    if(d==7)
        return "pqrs";
    if(d==8)
        return "tuv";
    if(d==9)
        return "wxyz";
    return "";
}

int keypad(int num,string output[])
{
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    int last=num%10;
    int smallNo=num/10;
    int smallOutput= keypad(smallNo,output);
    string options=getstring(last);

    for(int i=0;i<options.size()-1;i++) //copy the array
        for(int j=0;j<smallOutput;j++)
        output[smallOutput*(i+1) +j]= output[j];

    for(int i=0;i<options.size();i++)
        for(int j=0;j<smallOutput;j++)
        {
            output[smallOutput*i + j]+=options.substr(i,1);
        }
        return smallOutput* options.size();

}

int main()
{
   int n;
   string output[1000];
   cin>>n;
   int no=keypad(n,output);
   for(int i=0;i<no;i++)
    cout<<output[i]<<endl;
}
