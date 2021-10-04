#include<iostream>
using namespace std;
int area(int a)
{
    cout<<"The area of square is: "<<endl;
    return a*a;
}
int area(int l, int b)
{
    cout<<"The area of rectangle is : "<<endl;
    return l*b;
}
int area(float r)
{
    cout<<"The area of circle is : "<<endl;
    return 3.14*r*r;
}
int area(float r, float h)
{
    cout<<"The area of cylinder is : "<<endl;
    return (2*3.14*r*h)+(2*3.14*r*r);
}

int main(){
    float g=6.75;
int d=   area(g);
   cout<< d;
    return 0;
}
