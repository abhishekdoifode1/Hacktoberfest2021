#include <iostream>
int main(){
    
    struct xyz{

        int x;
    };

    struct xyz obj1={1}; //creating struct object
    struct xyz obj2= obj1; //Copy of that object

    printf("%d",obj2.x); //access using copy 
    obj2.x=100;          //changing value using copy object
    printf("%d",obj1.x); //access value using original object
return 0;
}
//Expected output: 
1
100
