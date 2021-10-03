/*
# Program for Binary to Octal Conversion
    Given a binary number as input, we need to write a program to convert the given binary number into equivalent octal number. i.e convert the number with base value 2 to base value 8. The base value of a number system determines the number of digits used to represent a numeric value. For example, the binary number system uses two digits 0 and 1, octal number system uses 8 digits from 0-7 and binary number system uses 10 digits 0-9 to represent any numeric value.

    Examples: 

        Input : 10101
        Output : 25

        Input : 101001
        Output : 51

        Input: 101        
        Output: 5      
*/

#include <iostream>
using namespace std;

int bin2Octal(int num)
{
    int octal = 0, base = 1;
    int dec = 0, b = 1;

    while (num != 0)
    {
        dec += (num % 10) * b;
        b *= 2;
        num /= 10;
    }

    while (dec != 0)
    {
        octal += ((dec % 8) * base);
        base *= 10;
        dec /= 8;
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
        printf("%d\n", bin2Octal(num));
    }

    return 0;
}