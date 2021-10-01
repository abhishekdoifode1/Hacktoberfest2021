#include<iostream>
using namespace std;
class Test
{
private: int count;
public: 
Test():
count(5){}
void operator ++()
{
count = count+1;
}
void display()
{
cout<<"count:"<<count;
};
int main()
{
Test t;
++t;
t.display();
return 0;
}