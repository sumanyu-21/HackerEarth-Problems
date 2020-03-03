# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1000000007;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n=s.length();
		ll **dp=new ll*[n];
		for(ll i=0;i<n;i++)
			dp[i]=new ll[3];
		ll columnsum0,columnsum1,columnsum2;
		columnsum0=0;
		columnsum1=0;
		columnsum2=0;
		dp[0][0]=s[0]%3==0?1:0;
		dp[0][1]=s[0]%3==1?1:0;
		dp[0][2]=s[0]%3==2?1:0;
		columnsum0=dp[0][0];
		columnsum1=dp[0][1];
		columnsum2=dp[0][2];
		for(ll i=1;i<n;i++)
		{
			if(s[i]%3==0)
			{
				dp[i][0]=(columnsum0+1)%mod;
				dp[i][1]=columnsum1;
				dp[i][2]=columnsum2;
			}
			else if(s[i]%3==1)
			{
				dp[i][0]=columnsum2;
				dp[i][1]=(columnsum0+1)%mod;
				dp[i][2]=columnsum1;
			}
			else
			{
				dp[i][0]=columnsum1;
				dp[i][1]=columnsum2;
				dp[i][2]=(columnsum0+1)%mod;
			}
			columnsum0=(columnsum0+dp[i][0])%mod;
			columnsum1=(columnsum1+dp[i][1])%mod;
			columnsum2=(columnsum2+dp[i][2])%mod;
		}
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			if(s[i]%2==0)
				ans=(ans+dp[i][0])%mod;
		}
		cout<<ans<<endl;

	}
}
