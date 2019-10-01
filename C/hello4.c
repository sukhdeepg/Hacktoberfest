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
