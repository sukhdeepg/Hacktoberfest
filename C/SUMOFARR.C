//This program is one of my favorites because it was the first Array program I ran successfully at the first run, on learning C programming
//Sum of Array Elements

#include<conio.h>
#include<stdio.h>

void main()
{
 int i, n, a[20], sum = 0;
 clrscr();

 printf("Enter number of elements: ");
 scanf("%d", &n);

 printf("Enter %d elements in array:\n", n);

//Input elements in Array
 for(i=0; i<n; i++)
  scanf("%d", &a[i]);

//Sum of array elements
 for(i=0; i<n; i++)
  sum+=a[i];

 printf("Sum of Array: %d", sum);
 getch();
}