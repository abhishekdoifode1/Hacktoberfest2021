#include <iostream>

using namespace std;
int main()
{
    int number1,number2,number3;  
  
    cout << "First number: ";
    cin>>number1;
  
    cout << "Second number: ";
    cin>>number2;
  
    cout << "Third number: ";
    cin>>number3;
  
    if(number1<=number2 && number1 <=number3){
        cout<<"\n Smallest number: "<<number1;
    }
    if(number2<=number1 && number2 <=number3){
        cout<<"\n Smallest number: "<<number2;
    }
    if(number3<=number1 && number3 <=number2){
        cout<<"\n Smallest number is: "<<number3;
    }
    getch();
    return 0;
}
