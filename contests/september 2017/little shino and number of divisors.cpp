# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1000000007;

ll power(ll a,ll b,ll m)
{
    long long res = 1;
    while (b){
        if (b & 1) res = (res * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr(n+1);
	ll total=1;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		arr[i]=x+1;
		total=(total*arr[i])%mod;
	}
	ll result=1;
	unordered_map<ll,ll>mymap(1000001);
	unordered_map<ll,ll>::iterator itr;
	for(int i=0;i<n;i++)
	{
	    if(arr[i]==1)
            continue;
        ll temp;
        itr=mymap.find(arr[i]);
        if(itr==mymap.end())
        {
            temp=power(arr[i],mod-2,mod);
            mymap.insert({arr[i],temp});
        }
        else
            temp=itr->second;
	    ll var=((arr[i]*(arr[i]-1))/2)%mod;
		ll ans=(((total*temp)%mod*var)%mod+1)%mod;
		result=(result*ans)%mod;
	}
	cout<<result;

}
