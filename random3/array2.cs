using System;
namespace FactorialCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Factorial Calculator\n");
            Console.Write("Enter a positive integer: ");
            int n = int.Parse(Console.ReadLine());
            if (n < 0)
            {
                Console.WriteLine("Error: Please enter a positive integer.");
                return;
            }
            Console.WriteLine($"The factorial of {n} is {CalculateFactorial(n)}.");
        }
        static int CalculateFactorial(int n)
        {
            if (n == 0)
            {
                return 1;
            }
            else
            {
                return n * CalculateFactorial(n - 1);
            }
        }
    }
}
