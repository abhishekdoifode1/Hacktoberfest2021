#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string input;
    if( num==1 || num==0)
    {

        return 1;
    }
    
    int n =num%10;
   switch(n)
   {
       case 2:
           input = "abc";
           break;
     case 3:
           input = "def";
           break;
     case 4:
           input = "ghi";
           break;
     case 5:
           input = "jkl";
           break;
     case 6:
           input = "mno";
           break;
   case 7:
           input = "pqrs";
           break;
 case 8:
           input = "tuv";
           break;
 case 9:
           input = "wxyz";
           break;

   }
    
 num = num/10;

    int smalloutput = keypad(num,output);
    int l = input.size();
    int c=0;
    int i=0;
int ans_size = smalloutput * input.size();
    string temp[ans_size];
    int k=0;
    for(i=0;i<input.size();i++)
    {
        for(int j=0;j<smalloutput;j++)
        {
            temp[k++] = output[j]+input[i];
        }
    }
    for(int i=0;i<ans_size;i++)
    {
       output[i]=temp[i]; 
    }
    return ans_size;
    
}