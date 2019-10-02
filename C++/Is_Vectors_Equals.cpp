// This is my favorite program because it uses XOR operation to check whether two vectors contains same elements order may be different in o(n) time.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n=0;
    cout<<"Enter number of element(Size of both vector will be same)"<<"\n";
    cin>>n;
    vector<ll>v1(n,0);
    vector<ll>v2(n,0);
    cout<<"Enter elements of vector 1 separated by space"<<"\n";
    for(ll i=0;i<n;i++)cin>>v1[i];
    cout<<"Enter elements of vector 2 separated by space"<<"\n";
    for(ll i=0;i<n;i++)cin>>v2[i];
    ll s1=0,s2=0;
    for(ll i=0;i<n;i++)
    {
        s1=s1^v1[i];
        s2=s2^v2[i];
    }
    if(s1==s2)cout<<"Both vector contains same elements"<<"\n";
    else cout<<"Both vector contains different elements"<<"\n";
    return 0;
}
