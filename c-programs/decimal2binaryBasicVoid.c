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
    int str[32];
    if (num == 0)
    {
        printf("0\n");
        return;
    }

    int i = 0;

    while (num > 0)
    {
        str[i] = num % 2;
        num = num / 2;
        ++i;
    }

    for (int j = i - 1; j >= 0; --j)
        printf("%d", str[j]);

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

        dec2bin(num);
    }

    return 0;
}