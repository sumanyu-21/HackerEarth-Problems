# include <iostream>
using namespace std;
typedef long long int ll;
ll algo(ll dp[],ll a[],ll b[],ll l,ll r,ll type)
{
	if(type==1)
	{
		dp[0]=a[l];
		//cout<<a[l]<<"  ";
		for(ll i=1;i<=r-l;i++)
		{
			if(i%2==0)
				dp[i]=dp[i-1]+a[l+i];//,cout<<a[l+i]<<"  ";
			else
				dp[i]=dp[i-1]+b[l+i];//,cout<<b[l+i]<<"  ";
           // cout<<dp[i]<<"  ";
		}
		return dp[r-l];
	}
	else
	{
		dp[0]=b[l];
		//cout<<b[l]<<"  ";
		for(ll i=1;i<=r-l;i++)
		{
			if(i%2==0)
				dp[i]=dp[i-1]+b[l+i];//,cout<<b[l+i]<<"  ";
			else
				dp[i]=dp[i-1]+a[l+i];//,cout<<a[l+i]<<"  ";
		}
		return dp[r-l];
	}
}
int main()
{
	ll n,q;
	cin>>n>>q;
	ll a[n+1],b[n+1];
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	ll ans[100005];
	ll k=0;
	while(q>=1)
	{
	    ll type,l,r;
	    cin>>type>>l>>r;
		ll dp[r];
        ll result=algo(dp,a,b,l,r,type);
		ans[k]=result;
		k++;
		q--;
	}
	for(ll i=0;i<k;i++)
		cout<<ans[i]<<endl;
}
