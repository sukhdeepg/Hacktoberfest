#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll BIT[200001];
void update(ll y,ll n)
{
	while(y<=n)
	{
		BIT[y]++;
		y+=(y)&(-y);
	}
}
ll query(ll y)
{
	ll c=0;
	while(y>0)
	{
		c+=BIT[y];
		y-=(y)&(-y);	
	}
	return(c);
}
bool cmp(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
	return(a.first>b.first);
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		memset(BIT,0,sizeof(BIT));
		ll cnt=0,prev=0,c;
		vector<pair<ll,ll> > v;
		for(ll i=0;i<n;i++)
		{
			cin>>c;
			v.push_back(make_pair(c,i+1));
		}
		sort(v.begin(),v.end(),cmp);
		update(v[0].second,n);
		for(ll i=1;i<n;i++)
		{
			if(v[i].first==v[i-1].first)
			{
				cnt+=prev;
				update(v[i].second,n);
			}
			else
			{
				prev=query(v[i].second);
				cnt+=prev;
				update(v[i].second,n);
			}
		}
		cout<<cnt<<endl;
	}
	return(0);
} 
