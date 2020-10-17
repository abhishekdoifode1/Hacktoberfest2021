// A one-liner program to solve FizzBuzz
// Using ternary operator
//Author: @rupal11

#include<iostream>

using namespace std;

int main()
{
	int i;
	for(i=1;i<=100;++i)
		(i%15==0) ? cout<<"FizzBuzz " : (i%3==0) ? cout<<"Fizz " : (i%5==0) ? cout<<"Buzz " : cout<<i<<" ";
	return 0;
}