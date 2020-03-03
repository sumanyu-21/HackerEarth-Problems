# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			if(x%2!=0)
				continue;
			while(x>1 && x%2==0)
			{
				x=x/2;
				cnt++;
			}
		}
		if(cnt%2==0)
			cout<<"Alan"<<endl;
		else
			cout<<"Charlie"<<endl;
	}
}