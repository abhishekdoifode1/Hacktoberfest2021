#include <cstdio>
#include <algorithm>
using namespace std;
int x[25005];
bool sol[200005];
bool bs(int v[],int st,int dr,int a)
{
    int med;
    while(st<=dr)
    {
        med = (st+dr)/2;
        if(v[med] == a)
            return 1;
        else
        {
            if(a>v[med])
                st = med+1;
            else
                dr = med-1;
        }
    }
    return 0;
}
int main()
{
    int n,m,i,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&y);
        sol[i] = bs(x,1,n,y);
    }
    for(i=1;i<=m;i++)
        printf("%d ",sol[i]);
    return 0;
}
