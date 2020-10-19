#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

void print(vector<int> v1){
    for (int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n"<<v1.front()<<" is at first position\n"; //print first element
    cout<<v1.back()<<" is at last position\n";  //print last element
    cout<<v1.at(3)<<" is at index position 3\n"; //here 3 specifies the index position
    cout<<"size : "<<v1.size()<<"\n"; //no of elements present in vector
    cout<<"max size: "<<v1.max_size()<<"\n"; //max no of elements that can be stored in vector
    cout<<"capacity: "<<v1.capacity()<<"\n"; // size of storage currently allocated to vector expressed in no of elements


}

int main(){
    vector<int> v1;
    v1.push_back(89); //pushed element at the end of the vector
    v1.push_back(56);
    v1.push_back(12);
    v1.push_back(45);
    v1.push_back(29);
    v1.push_back(82);
    print(v1);
    return 0;
}
