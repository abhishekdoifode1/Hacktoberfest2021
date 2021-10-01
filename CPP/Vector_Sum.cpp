#include <bits/stdc++.h>
using namespace std;

int main()
{
 vector<int> v;
 v = {1,2,3,4};
 int sum=0;
 int size = v.size();
 
 for(int i=0; i<size; i++){
    sum = sum + v[i];
 }
  cout<<sum;
  return 0;
}
