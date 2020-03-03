# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxtime(ll arr[],ll n,ll k)
{
	ll maxans=-1;
	ll dp[n];
	/*if(arr[0]>=0)
		dp[0]=arr[i];
	else dp[0]=0;
	maxans=dp[0];*/
	for(ll i=0;i<=k;i++)
	{
		if(arr[i]<0)
			dp[i]=0;
		else
			dp[i]=arr[i];
        maxans=max(maxans,dp[i]);
	}
	ll maxl=0;
	for(ll i=k+1;i<n;i++)
	{
	    maxl=max(maxl,dp[i-k-1]);
		if(arr[i]<0)
			dp[i]=0;
		else
		{
			dp[i]=arr[i]+maxl;
		}
		//maxl=max(maxl,dp[i-k]);
		maxans=max(maxans,dp[i]);
	}
	/*for(ll i=0;i<n;i++)
        cout<<dp[i]<<"  ";*/
	return maxans;

}
int main()
{
	ll t;
	cin>>t;
	ll ans[251];
	ll j=0;
	while(t)
	{
		ll n,k;
		cin>>n>>k;
		ll arr[n];
		for(ll i =0;i<n;i++)
			scanf("%lld",&arr[i]);
		ll result=maxtime(arr,n,k);

		ans[j]=result;
		j++;
		t--;
	}
	for(ll i=0;i<j;i++)
		cout<<ans[i]<<endl;

}
