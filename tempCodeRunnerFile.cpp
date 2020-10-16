#include <iostream>
using namespace std;
int main()
{
    int *x;
    int a;
    *x=&a;
    for(int i=1;i<5;i++)
    {
        a++;
        cout<<a<<endl<<i<<endl;
    }
    return 0;
}