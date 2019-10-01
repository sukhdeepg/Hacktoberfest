#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// calculates x power y mod m in O(logn) time
int binaryExp(ll x, ll y, ll m)
{
    ll ans = 1;
    x = x%m;
    while(y > 0)
    {
        if(y&1)
            ans = (res*x)%m;
        y = y>>1;
        x = (x*x)%m;
    }
    return ans;
}
int main()
{
    int x=2;
    int y=100;
    int m=1e9+7;

    cout<<binaryExp(x,y,m);
    return 0;
}
