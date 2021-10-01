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
#include <iostream>
using namespace std;

int *dec2bin(int num)
{
    int *binaryNum = new int[33];

    int i = 0;

    while (num > 0)
    {
        binaryNum[i] = num % 2;
        num = num / 2;
        ++i;
    }

    binaryNum[32] = i - 1;

    return binaryNum;
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

        int *res = dec2bin(num);

        for (int j = res[32]; j >= 0; --j)
            printf("%d", res[j]);

        printf("\n");
    }

    return 0;
}