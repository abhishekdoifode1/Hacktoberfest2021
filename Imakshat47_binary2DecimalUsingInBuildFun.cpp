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

int main()
{

    // for test case
    int t;

    scanf("%d\n", &t);

    while (t--)
    {
        // main logic
        char str[100001];

        scanf("%s", str);

        printf("%d\n", stoi(str, 0, 2));
    }

    return 0;
}