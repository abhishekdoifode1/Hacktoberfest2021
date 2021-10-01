using System;

namespace binarysearch
{
    class Program
    {
        public static void Main()
        {
            int[] a = new int[100];
            Console.Write("Number of Elements in the array: ");
            string s = Console.ReadLine();
            int x = Int32.Parse(s);
            Console.Write("Enter array elements:  ");
            for (int i = 0; i < x; i++)
            {
                string s1 = Console.ReadLine();
                a[i] = Int32.Parse(s1);
            }
            Console.Write("\nEnter Search element: ");
            string s3 = Console.ReadLine();
            int x2 = Int32.Parse(s3);
            int low = 0;
            int high = x - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (x2 < a[mid])
                    high = mid - 1;
                else if (x2 > a[mid])
                    low = mid + 1;
                else if (x2 == a[mid])
                {
                    Console.WriteLine("Element {0} found at index {1}\n", x2, mid + 1);
                    return;
                }
            }
            Console.WriteLine("Search unsuccessful");
        }
    }
}
