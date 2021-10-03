#include <iostream>
#include<conio.h>
using namespace std;

int fact(int n)
{
   if(n==0)
        return 0;
   return n*factorial (n-1);
}

int main()
{
    unsigned int n;
    unsigned long long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

//     for(int i = 1; i <=n; ++i)
//     {
//         factorial *= i;
//     }

    
    cout << "Factorial of " << n << " = " << fact(n);    
    return 0;
}
