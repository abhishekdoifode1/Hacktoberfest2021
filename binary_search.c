#include<stdio.h>
int main()
{
   int c, first, last, middle, n, search, array[100],i,j,temp;
   printf("Enter number of elements:\n");
   scanf("%d",&n); 
   printf("Enter %d integers:\n", n);
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]); 
    for(i=n-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(array[j]>array[j+1]){
           temp=array[j];
           array[j]=array[j+1];
           array[j+1]=temp;
        }
      }
   }

   printf("After Sorting : \n");
   for(i=0;i<n;i++)
      printf(" %d",array[i]);
   printf("Enter the value to find:\n");
   scanf("%d", &search);
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d is present at index %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
   return 0;  
}
