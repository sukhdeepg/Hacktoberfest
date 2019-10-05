//Stack operations using array

#include<bits/stdc++.h>
using namespace std;
class Stack
{
public:
	int size,top,a[10];
	Stack(){
	 size = 10;
	 top = -1;
	 a[10];}
	void push(int x)
	{
		if(top == size-1)
			cout<<"Stack overflow"<<endl; // Checks overflow condition
		else{
		a[++top] = x;
		cout<<"Pushed "<< x<<endl;}
	}
	void pop()
	{
		if(top==-1)
			cout<<"Stack underflow"<<endl; // Checks underflow condition
		else{
		cout<<"Popped "<< a[top]<<endl;
		top--;}
	}
	void show()
	{
		cout<<"Stack:";
		for(int i=top;i>=0;i--)
			cout<<a[i]<<" ";
		cout<<endl;
	}
};
int main()
{
	Stack s;
	char ch = 'y';
	int m,x;
	// Menu driven
	while(ch == 'y')
	{
		cout<<"Enter 1 to push, 2 to pop, 3 to see stack ";
		cin>>m;
		switch(m){
			case 1: {cout<<"Enter element "; cin>>x; s.push(x); break;}
			case 2: {s.pop(); break;}
			case 3: {s.show(); break;}
			default: cout<<"Invalid choice"<<endl;
		}
		cout<<"Want to try another operation? (press y for yes) ";
		cin>>ch;
	}
}
