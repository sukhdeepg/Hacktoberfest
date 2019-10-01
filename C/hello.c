/*PROGRAM TO ILLUSTRATE THE USE OF CAST OPERATOR*/
#include<stdio.h>
int main()
{
int x=5, y=2;
float p,q;
p=x/y;
printf("p=%f\n",p);
q=(float)x/y;
printf("q=%f\n",q);
return 0;
}

/*PROGRAM TO FIND BIGGEST NUMBER FROM THREE GIVEN NUMBER*/
#include(stdio.h)
int main(void)
{
int a,b,c,big;
printf("enter three numbers: ");
scanf("%d%d%d", &a,$b,&c);
if(a>b)
{
if(a>c)
big=a;
else
big=c;
}
else
{
if(b>c)
big=b;
else
big=c;
}
printf("biggest number is %d\n",big);
return 0;
}

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

/*program to convert a binary number to a decimal number*/
#include<stdio.h>
int main(void)
{
int n,nsave,rem,d,j=1,dec=0;
scanf("%d",&n);
nsave=n;
while(n>0)
{
rem=n%10;
d=rem*j;
dec+=d;
j*=2;
n/=10;
}
printf("binary number=%d, decimal number=%d\n" ,nsave,dec);
return 0;
}
