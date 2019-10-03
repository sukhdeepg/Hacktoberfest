*PROGRAM TO ILLUSTRATE THE USE OF CAST OPERATOR*/
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
