#include<stdio.h>

int factorial(int n);

int main(){
  int a;
 printf("Enter the number for which you want to calculate the factorial for\n");
 scanf("%d", &a);
  printf("The factorial of %d is %d\n", a, factorial(a));
  return 0;
}

int factorial(int n){
  if(n==1 || n==0){
    return 1;
  }
  
  else{
    return n * factorial(n-1);
  }
  
}
