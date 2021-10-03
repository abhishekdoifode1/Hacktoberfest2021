// https://www.hackerrank.com/challenges/simple-array-sum/submissions/code/138618297

#include <bits/stdc++.h>

using namespace std;


void simpleArraySum() {
    int n,sum=0 ;
    cin>>n;
    int ar[n];
    if(n>0)
    {for(int i=0; i<n; i++)
    {
    
    cin>>ar[i];
    {if(ar[i]<=1000)
    
sum= sum + ar[i];
    }
    }
    }
    cout<<sum;

}

int main()
{ simpleArraySum();

}
