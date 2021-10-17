#include <stdio.h>
int main()
{
  int n1, n2;
  printf ("Enter first number: ");
  scanf ("%d", &n1);
  printf ("Enter second number: ");
  scanf ("%d", &n2);
  
  int sum = n1 + n2;
  
  printf("The Sum of %d and %d is %d\n", n1, n2, sum);
  return 0;
}
