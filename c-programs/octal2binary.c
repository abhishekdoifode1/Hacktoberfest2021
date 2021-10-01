// # Write a program to convert Octal to Binary
/*
    Examples: 

        Input : 25
        Output : 10101

        Input : 51
        Output : 101001

        Input: 5        
        Output: 101      
*/

#include <stdio.h>

int octal2bin(int octal)
{
    int dec = 0, base = 1;

    while (octal != 0)
    {
        dec += (octal % 10) * base;
        base *= 8;
        octal /= 10;
    }

    int bin = 0;
    base = 1;

    while (dec != 0)
    {
        bin += ((dec % 2) * base);
        base *= 10;
        dec /= 2;
    }

    return bin;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int num;
        scanf("%d", &num);
        printf("%d\n", octal2bin(num));
    }

    return 0;
}