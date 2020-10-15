#include <iostream>
using namespace std;
int main()
{
    int *x,*y;
    int num1=8,num2=9;
    x=&num1;
    y=&num2;
    int sum;
    sum = *x + *y;
    cout<<sum;
    return 0;
}