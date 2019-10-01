//Euclidean Algorithm for GCD

#include<bits/stdc++.h>
using namespace std;

long long int GCD( long long int a , long long int b)
{
    if (b == 0) 
        return a; 
    
    return gcd(b, a % b);
}
int main()
{
    long long int a, b;
    a = 10;
    b = 4;
    long long result = GCD(a,b);
    cout<<"Gcd of a and b is "<<result<<endl;
}
