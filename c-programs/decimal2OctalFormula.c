/*
# Program for Decimal to Octal Conversion
    Given a decimal number as input, we need to write a program to convert the given decimal number into equivalent octal number. i.e convert the number with base value 10 to base value 8. The base value of a number system determines the number of digits used to represent a numeric value. For example, the binary number system uses two digits 0 and 1, octal number system uses 8 digits from 0-7 and decimal number system uses 10 digits 0-9 to represent any numeric value.

    Examples: 

        Input : 16
        Output : 20

        Input : 10
        Output : 12

        Input: 33
        Output: 41

        Time Complexity: O(1)         
*/

#include <stdio.h>

int dec2Octal(int num)
{
    int octal = 0, base = 1;
    while (num != 0)
    {
        octal += ((num % 8) * base);        
        base *= 10;
        num /= 8;
    }
    return octal;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int num;
        scanf("%d", &num);
        printf("%d\n", dec2Octal(num));
    }

    return 0;
}