#include <bits/stdc++.h>
using namespace std;

int prime[1000005];
void sieve(){
	prime[0] = prime[1] = 0;
	for(int i=2;i<1000005;i++)
		prime[i] = i;
	for(int i=2;i<sqrt(100005);i++){
		if(prime[i] == i)
			for(int j=i*i;j<100005;j+=i)
				prime[j] = min(prime[j],i);
	}
}

int main(){
	sieve();
	int n;
	cin>>n;
	cout<<"Prime Factors of "<<n<<endl;
	while(n>1){
		int x = prime[n];
		cout<<x<<" ";
		while(n>1 && n%x == 0)
			n /= x;
	}
	cout<<endl;
}