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
#include <stdio.h>
int bin2dec(int num)
{
    int dec = 0, base = 1;
    while (num != 0)
    {
        dec = dec + ((num % 10) * base);
        base *= 2;
        num /= 10;
    }
    return dec;
}

int main()
{

    // for test case
    int t;
    scanf("%d", &t);

    while (t--)
    {
        // main logic
        int num;
        scanf("%d", &num);    

        printf("%d\n", bin2dec(num));
    }

    return 0;
}