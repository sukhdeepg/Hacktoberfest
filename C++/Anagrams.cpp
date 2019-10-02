#include<iostream>
#include<string.h>
using namespace std;

main()
{
string a,b;
int n,x,y;
int count;

cin>>n;

for(int i=1; i<=n; i++)
{
count=0;
cin>>a>>b;

x=a.length();
y=b.length();
for(int j=0; j<x; j++)
{

for(int k=0; k<y; k++)
{
if(a[j]==b[k])
{
b[k]=0;
count++;
break;
}
}

}

cout<<(x-count)+(y-count)<<endl;
}

return 0;
}
