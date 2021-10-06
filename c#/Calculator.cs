using System;

public class Calculator
{
    public int Addition(int a, int b)
    {
        return a + b;
    }
    
    public int Subtraction(int a, int b)
    {
        return a - b;
    }
    
    public int Multiplication(int a, int b)
    {
        return a * b;
    }
    
    public double Division(int a, int b, out double remainder)
    {
        remainder = a % b;
        return Convert.ToInt32(a / b);
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Calculator c = new Calculator();
        
        Console.WriteLine("Enter the operator");
        char op = Console.ReadLine()[0];
        
        Console.WriteLine("Enter the operands");
        int num1 = int.Parse(Console.ReadLine());
        int num2 = int.Parse(Console.ReadLine());
        
        switch(op)
        {
            case '+':
                Console.WriteLine("Result of {0} {1} {2} is {3}", num1, op, num2, c.Addition(num1, num2));
                break;
            case '-':
                Console.WriteLine("Result of {0} {1} {2} is {3}", num1, op, num2, c.Subtraction(num1, num2));
                break;
            case '*':
                Console.WriteLine("Result of {0} {1} {2} is {3}", num1, op, num2, c.Multiplication(num1, num2));
                break;
            case '/':
                double remainder;
                Console.WriteLine("Result of {0} {1} {2} is {3}\nRemainder = {4}", num1, op, num2, c.Division(num1, num2, out remainder), remainder);
                break;
            default:
                Console.WriteLine("Invalid Operator");
                break;
        }
    }
}
