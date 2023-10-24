#include<iostream>
using namespace std;
int main()
{
    long int N;
    int Q;
    cin>>N;
    cin>>Q;
    int A[N],X,Y,i,j;
    
    for(i=0;i<N;i++)
    cin>>A[i];

    for(i=1;i<=Q;i++)
    {
        int sum=0;
        short int a;
        cin>>a;
        if(a==1)
            {
                cin>>X>>Y;             
                A[X]=Y;
            }
        else if (a==2)
        {
           cin>>X>>Y;
           for(j=X;j<=Y;j++)
           {   
               sum+=A[j];
           }
           cout<<sum<<endl;
        }
        

        
    }
    return 0;
}