using System;

namespace variableFizzBuzz
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please enter a number for fizz:");
            int x = int.Parse(Console.ReadLine());
            Console.WriteLine("Please enter a number for buzz:");
            int y = int.Parse(Console.ReadLine());
            
            for (int i = 1; i < 101; i++)
            {
                if (i % x == 0 && i % y == 0)
                {
                    Console.WriteLine("fizzBuzz");
                }
                else if (i % x == 0)
                {
                    Console.WriteLine("fizz");
                }
                else if (i % y == 0)
                {
                    Console.WriteLine("buzz");
                }
                else
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}
