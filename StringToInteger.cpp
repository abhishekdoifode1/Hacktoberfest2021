/*
String to Integer
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/
#include <iostream>
using namespace std;

int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallpower = power(x, n - 1);
    return smallpower * x;
}
int stringToNumber(char input[]) {

    if(length(input)==1)
        return input[0]-48;
    
    int a=stringToNumber(input+1);
    int b=input[0]-48;
    
    return b*power(10,length(input)-1)+a;
}
int main()
{
    char input[100];
    cin >> input;
    cout << stringToNumber(input);
    return 0;
}

