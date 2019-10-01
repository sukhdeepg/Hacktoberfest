#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
  int n,k;
  printf("%s\n","Enter number of elements:");
  scanf("%d",&n);
  int a[n];
  printf("%s\n","Enter the elements:");
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("%s","Enter which kth maximum element to find:");
  scanf("%d",&k);
  qsort(a,n,sizeof(int),cmpfunc);
  printf("%d\n",a[k-1]);
	return 0;
}
