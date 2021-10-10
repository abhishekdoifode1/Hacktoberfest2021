#include <bits/stdc++.h>
using namespace std;
int main(){
  cout<<"Enter n"<<endl;
  int n;
  
  cin>>n;
  int j=2;
  int ans=2;
  int cur=2;
  int a[n];
  int pd= a[j]-a[j-1];
  for(int i=0; i<n;i++){
    cin>>a[i];
  }
  while(j<n){
    if(a[j]-a[j-1]==pd)
      cur++;
    else{
      pd= a[j]-a[j-1];
      cur=2;
      
    }
    ans=max(cur,ans);
    j++;
  }
  cout<<"The length of the longest arithmetic subarray is "<<ans<<endl;

}
