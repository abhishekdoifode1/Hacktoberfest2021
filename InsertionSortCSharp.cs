using System;
namespace InsertionSort{
   class Example {
      static void Main(string[] args) {
         int[] arr = new int[10] { 23, 9, 85, 12, 99, 34, 60, 15, 100, 1 };
         int n = 10, i, j, val, flag;
         Console.WriteLine("Insertion Sort");
         Console.Write("Initial array is: ");
         for (i = 0; i < n; i++) {
            Console.Write(arr[i] + " ");
         }
         for (i = 1; i < n; i++) {
            val = arr[i];
            flag = 0;
            for (j = i - 1; j >= 0 && flag != 1; ) {
               if (val < arr[j]) {
                  arr[j + 1] = arr[j];
                  j--;
                  arr[j + 1] = val;
               }
               else flag = 1;
            }
         }
         Console.Write("\nSorted Array is: ");
         for (i = 0; i < n; i++) {
            Console.Write(arr[i] + " ");
         }
      }
   }
}
