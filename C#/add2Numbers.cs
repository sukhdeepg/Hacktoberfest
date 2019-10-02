using System;
 
public class functionexcercise
{
    public static int Sum(int num1, int num2)
    {
        int total;
        total = num1 + num2;
        return total;
    }
 
    public static void Main()
    {        
        Console.Write("Enter two numbers: ");
        int number1 = Convert.ToInt32(Console.ReadLine());
        int number2 = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("\nThe sum of two numbers is : {0} \n", Sum(number1, number2));
 
        Console.ReadLine();
    }
}
