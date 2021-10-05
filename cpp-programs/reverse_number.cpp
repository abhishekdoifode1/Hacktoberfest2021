//c++ program to reverse number
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int number, r;
    int reverse_number = 0;
    cout<<"Enter no. you want to reverse: ";
    cin >> number;
    int i;
    while (number > 0)
    {
        r = number % 10;
        reverse_number = reverse_number * 10 + r;
        number = number / 10;
    }

cout<<reverse_number;
}
