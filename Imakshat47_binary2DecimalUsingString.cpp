/*
# Program for Binary To Decimal Conversion

    Given a binary number as input, we need to write a program to convert the given binary number into an equivalent decimal number.

    Examples : 

        Input : 111
        Output : 7

        Input : 1010
        Output : 10

        Input: 100001
        Output: 33
*/
#include <iostream>
using namespace std;

int bin2dec(string num)
{
    int dec = 0, base = 1;
    for (int i = num.length() - 1; i >= 0; --i)
    {
        if (num[i] == '1')
            dec += base;
        base *= 2;
    }
    return dec;
}

int main()
{

    // for test case
    int t;

    scanf("%d\n", &t);

    while (t--)
    {
        // main logic
        string str;

        getline(cin, str);

        printf("%d\n", bin2dec(str));
    }

    return 0;
}