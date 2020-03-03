# include <iostream>
# include <bits/stdc++.h>
# define mod 1000000007;
using namespace std;
typedef long long int ll;
ll algo(ll **dp,int n,int p)
{
	ll sumrow=1;
	for(ll j=0;j<=p;j++)
		dp[1][j]=0;
	/*for(ll i=1;i<=n;i++)
		dp[i][0]=1;*/
    dp[1][0]=1;
	if(n>=2)
        dp[2][0]=1;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=0;j<=p;j++)
		{
			if(j!=0)
			{
				dp[i][j]=dp[i-1][j-1];
				sumrow=(sumrow+dp[i][j])%mod;
			}
			else if(j==0 && i!=2)
			{
				dp[i][j]=sumrow;
				sumrow=dp[i][j];
			}
		}
	}
	return sumrow;
}
int main()
{
	ll t;
	cin>>t;
	ll ans[105];
	ll k=0;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		ll **dp=new ll*[n+1];
		for(ll i=0;i<=n;i++)
			dp[i]=new ll[p];
		ll result=algo(dp,n,p-1);
		for(ll i=1;i<=n;i++)
		{
			for(ll j=0;j<=p-1;j++)
				cout<<dp[i][j]<<"  ";
			cout<<endl;
		}
		ans[k]=result;
		k++;
	}
	for(ll i=0;i<k;i++)
		cout<<ans[i]<<endl;
}
