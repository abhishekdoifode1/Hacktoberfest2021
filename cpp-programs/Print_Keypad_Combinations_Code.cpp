#include <iostream>
#include <string>
using namespace std;


string getString(int d){
    if(d==2){
        return "abc";
    }
    if(d==3){
        return "def";
    }
    if (d==4){
        return "ghi";
    }
    if(d==5){
        return "jkl";
    }
    if(d==6){
        return "mno";
    }
    if(d==7){
        return "pqrs";
    }
    if(d==8){
        return "tuv";
    }
    if(d==9){
        return "wxyz";
    }
    return "";
}

void printKeypad(int num , string output)
{
    if(num==0){
        cout << output << endl ; 
        return ; 
    }
    int a = num % 10 ;
    int b = num / 10 ;
    string options=getString(a);
    for(int i=0;i<options.length();i++){
        printKeypad(b , options[i]+output);
    }
 
}

void printKeypad(int num){
    
    printKeypad(num, "" ) ;
}