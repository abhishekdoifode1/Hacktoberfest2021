/*
# Program for Decimal to Binary Conversion

    Given a decimal number as input, we need to write a program to convert the given decimal number into equivalent binary number.

    Examples:

        Input : 7
        Output : 111

        Input : 10
        Output : 1010

        Input: 33
        Output: 100001
*/
#include <stdio.h>
void dec2bin(int num)
{
    for (int i = 31; i >= 0; --i)
    {
        int k = num >> i;
        if (k & 1)
            printf("1");
        else
        {
            printf("0");
        }        
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        int num;
        scanf("%d", &num);

        if (num == 0)
        {
            printf("0\n");
            continue;
        }

        dec2bin(num);
    }

    return 0;
}