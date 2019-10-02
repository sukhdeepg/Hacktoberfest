// Sample code to perform I/O:

#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	int n,i;
	char a[100];
	cin>>a;
	n=strlen(a);

	  for (i=0;i<n;i++)
	  {
	if (a[i]>=97 && a[i]<=122)
	{a[i]=a[i]-32;}
	else
	{a[i]=a[i]+32;}
	  }
	
	cout<<a;
	return 0;}
