using System;

namespace FactorialRecursively
{
    public class Factorial
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Factorial calculator.\nEnter your number:");
                var line = Console.ReadLine();
                int num = Convert.ToInt32(line);
                Console.WriteLine(String.Format("The factorial of {0:d} is {1:d}.", num, GetFactorial(num)));
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error! " + ex.Message);
            }
        }

        static int GetFactorial(int number)
        {
            if (number <= 0)
            {
                return 1;
            }
            return number * GetFactorial(--number);
        }
    }
}
