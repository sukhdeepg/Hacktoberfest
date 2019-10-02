// Sample code to perform I/O:
 #include <iostream>

using namespace std;

int main() {
	int d,n[100000],a,m,x;
	cin>>a;
for (int i=0;i<a;i++)
{	cin>>n[i];
	d=n[i]%6;
	m=n[i]/6;
	x=m%2;

 
if (n[i]%12!=0 && (x==0 || n[i]%6==0))

{
switch (d)
{
case 0:
	n[i]=n[i]+1;
    cout<<n[i]<<" WS"<<endl;
    break;

case 1:

	n[i]=n[i]+11;
	cout<<n[i]<<" WS"<<endl;
	break;
	
case 2:
	n[i]=n[i]+9;
	cout<<n[i]<<" MS"<<endl;
	break;
	
case 3:
	n[i]=n[i]+7;
	cout<<n[i]<<" AS"<<endl;
break;

case 4:
	 	
	n[i]=n[i]+5;
	cout<<n[i]<<" AS"<<endl;
	break;
	
case 5:
	n[i]=n[i]+3;
	cout<<n[i]<<" MS"<<endl;
	break;}
}
else
	{
		
	
	switch (d)
{
case 0:
	n[i]=n[i]-11;
    cout<<n[i]<<" WS"<<endl;
    break;

case 1:

	n[i]=n[i]-1;
	cout<<n[i]<<" WS"<<endl;
	break;
	
case 2:
	n[i]=n[i]-3;
	cout<<n[i]<<" MS"<<endl;
	break;
	
case 3:
	n[i]=n[i]-5;
	cout<<n[i]<<" AS"<<endl;
break;

case 4:
	 	
	n[i]=n[i]-7;
	cout<<n[i]<<" AS"<<endl;
	break;
	
case 5:
	n[i]=n[i]-9;
	cout<<n[i]<<" MS"<<endl;
	break;
}
}
}
	return 0;}
