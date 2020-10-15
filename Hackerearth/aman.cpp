#include <iostream>
using namespace std;
int main(){
    int d,i,t=0;
    cin>>d;
    int r[d];
    short int x[d];
    for(i=0;i<d;i++)
    {
        cin>>r[i]>>x[i];
        // cout<<endl;
        if((44*r[i]/7)<=(100*x[i]))
        t++;

    }
    cout<<t;
    return 0;
}