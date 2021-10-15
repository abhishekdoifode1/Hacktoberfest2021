#include<iostream>
using namespace std;
int main()
{
    int f=-1 , r=-1 , n , ch ,i , val;
    cout<<"enter number of elements in queue:"<<endl;
    cin>>n;
    int Q[n];
    do
    {
        cout<<"===Circular QUEUE==="<<endl;
        cout<<"1.insertion"<<endl << "2.deletion"<<endl << "3.search" <<endl<<"4.change"<<endl<< "5.display" << endl <<"6.exit"<<endl;
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            if ((f == 0 && r == n-1) || (f == r+1)) {
                cout<<"Queue Overflow \n";
             }
             else{
             cout<<"enter value:";
             cin>>val;
            if (f == -1) {
                    f = 0;
                    r = 0;
            }
            else {
                if (r == n - 1)
                    r = 0;
                else
                    r = r + 1;
            }
            Q[r] = val ;
            cout<<"value inserted.."<<endl;
            }
            break;
        case 2:
            int y;
             if (f == -1) {
                cout<<"Queue Underflow\n";
            }
            else{
                y=Q[f];
                if(f == r){
                    f = r = -1;
                    cout<<"deleted value:"<<y;
                }
                else{
                    if(f == n){
                        f = 0;
                        cout<<"deleted element :"<<y;
                    }
                    else{
                        f=f+1;
                        cout<<"deleted element:"<<y;
                    }
                }
            }
            break;
        case 3:
                   cout<<"enter the position to search the element:"<<endl;
                    cin>>i;
                    if(f==r)
                        cout<<"queue is empty"<<endl;
                    else
                    {
                        val = Q[f+i-1];
                        cout<<"searched value :"<<val<<endl;
                    }
            break;
        case 4:
            cout<<"enter position of the element whose value is to be changed:";
                    cin>>i;
                    if(f==r)
                        cout<<"queue is empty";
                    else
                    {
                        cout<<"enter value:";
                        cin>>val;
                        Q[f+i-1]=val;
                        cout<<"value changed:"<<val<<endl;
                    }

            break;
        case 5:
            if (f == -1) {
                cout<<"Queue is empty"<<endl;
            }
            cout<<"Queue elements are :\n";
            if (f <= r) {
                while (f <= r){
                    cout<<Q[f]<<" ";
                    f++;
                }
            }
            else {
                while (f <= n - 1) {
                    cout<<Q[f]<<" ";
                    f++;
                }
                f = 0;
                while (f <= r) {
                    cout<<Q[f]<<" ";
                    f++;
                }
           }
           cout<<endl;

            break;
        case 6:
            return 0;
            break;
        default:
            cout<<"invalid choice"<<endl;
        }
    }while(ch!=6);
        return 0;
}


