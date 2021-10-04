#include<iostream>
using namespace std;


int coconuts(int xa,int xb,int Xa,int Xb){
    int p,q,r;
    p=Xa/xa;
    q=Xb/xb;
    r=p+q;
    return r;
}


int main(){
    int xa,xb,Xa,Xb,T;

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>xa>>xb>>Xa>>Xb;
        cout<<coconuts(xa,xb,Xa,Xb);
    }


return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d;
        if(c%a==0 && d%b==0){
            e=c/a;
            f=d/b;
        }
        else{
           e=c/a +1;
           f=d/b+1;
        }

        cout<<e+f<<"\n";

    }
}
