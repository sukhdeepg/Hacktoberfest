/*program to find factorial of any number*/
#include(stdio.h)
int main(void)
{
int n,num;
long fact=1;
printf("enter a number : ");
scanf("%d" ,&n);
num=n;
if(n=0)
printf("No factorial of negative number\n");
else
{
while(n>1)
{
fact*=n;
n--1
}
printf("Factorial of %d=%ld\n" ,num,fact);
}
return 0;
}
