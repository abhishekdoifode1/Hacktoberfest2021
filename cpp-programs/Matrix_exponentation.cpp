#include <bits/stdc++.h>
 
using namespace std;
 

void multiply(int Fibonnaci[2][2], int M[2][2]) {
   int a = Fibonnaci[0][0] * M[0][0] + Fibonnaci[0][1] * M[1][0];
   int b= Fibonnaci[0][0] * M[0][1] + Fibonnaci[0][1] * M[1][1];
   int c = Fibonnaci[1][0] * M[0][0] + Fibonnaci[1][1] * M[1][0];
   int d = Fibonnaci[1][0] * M[0][1] + Fibonnaci[1][1] * M[1][1];
   Fibonnaci[0][0] = a;
   Fibonnaci[0][1] = b;
   Fibonnaci[1][0] = c;
   Fibonnaci[1][1] = d;
}


void power(int Fibonnaci[2][2], int n) {
   
   if (n == 0 || n == 1)
      return;
   
   int M[2][2] = {{1,1},{1,0}};
   
   power(Fibonnaci, n / 2);
  
   multiply(Fibonnaci, Fibonnaci);
  
   if (n % 2 != 0)
      multiply(Fibonnaci, M);
}

 
int solve(int o)
{
    
   int Fibonnaci[2][2] = {{1,1},{1,0}};
 
    int number; cin >> number;

    if(number < 0)
        return -1;
 
    if(number==0)
        return 0;

    power(Fibonnaci, number-1);
    return Fibonnaci[0][0];
}
 
int main()
{
 
    int test_cases = 1;
    cin >> test_cases;
    for(int i=0;i<test_cases;i++)
    {
        cout << solve(i);
    }
}
