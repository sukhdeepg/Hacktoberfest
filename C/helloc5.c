#include <stdio.h>

#define MAX(x,y) ((x>y)?x:y)

int main()
{
	int a,b,max;
	
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);	
	
	max=MAX(a,b);
	printf("Maximum number is: %d\n",max);
	
	return 0;
}


// // OUTPUT
// Enter first number: 100 
// Enter second number: 200
// Maximum number is: 200