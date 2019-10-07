import java.math.io;
public class factorial
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
int fact=1;
int n=in.nextInt();
for(int i=n;i>0;i++)
{
fact=fact * i;
}
System.out.println("Factorial of "+n+" is: "+fact);
}
}
