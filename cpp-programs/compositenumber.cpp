    #include <iostream>  
    using namespace std;  
    int main()  
    {  
      int n, i, m=0, flag=0;  
      cout << "Enter the Number to check composite: ";  
      cin >> n;  
      m=n/2;  
      for(i = 2; i <= m; i++)  
      {  
          if(n % i == 0)  
          {   
              flag=1;  
              break;  
          }  
      }  
      if (flag==1)  
          cout << "Number is composite ."<<endl;  
      return 0;  
    }  
