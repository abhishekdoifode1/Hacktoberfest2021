#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{   int n;
    cout << "enter n" << endl;
    cin >> n;
    int a[n][n];
    for(int i=0;i<n;i++)
    
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "entered matrix" << endl;
    for(int i=0;i<n;i++)
    
    {
        for(int j=0;j<n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    vector <int> v;
    int row = n;
    int col = n;
    int sr=0, sc=0, er=row-1 ,ec=col-1;
    
    
    int count=0;
    while(sr<=er && sc<=ec)
    {
        for(int i=sc;i<=ec;i++)
        {
            v.push_back(a[sr][i]);
            count++;
        }
        sr++;
        if(count==n*n)
        {
            break;
        }
        for(int i=sr;i<=er;i++)
        {
            v.push_back(a[i][ec]);
            count++;
        }
        ec--;
        if(count==n*n)
        {
            break;
        }
        for(int i=ec;i>=sc;i--)
        {
            v.push_back(a[er][i]);
            count++;
        }
        er--;
        if(count==n*n)
        {
            break;
        }
        for(int i=er;i>=sr;i--)
        {
            v.push_back(a[i][sc]);
            count++;
        }
        sc++;
        if(count==n*n)
        {
            break;
        }
    }
    
    for(int i = 0;i<row*col;i++)
    {
        cout << v.at(i) << " ";
    }
    
    

    return 0;
}
// Anjani