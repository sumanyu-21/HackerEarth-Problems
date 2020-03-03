# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll algo(string s,ll n,ll dp[])
{
	ll maxbar=0;
	dp[0]=1;
	dp[1]=2;
	for(ll i=2;i<n;i++)
	{
		if(s[i]!=s[i-1] || s[i]!= s[i-2] || s[i-1]!=s[i-2])
			dp[i]=dp[i-1]+1;
		else if(s[i]==s[i-1] && s[i]==s[i-2] && dp[i-1]%3==2)
			dp[i]=2;
		else if(s[i]==s[i-1] && s[i]==s[i-2] && dp[i-1]%3!=2)
			dp[i]=dp[i-1]+1;
		if(dp[i]%3==0)
			maxbar=max(maxbar,dp[i]);

	}
	return n-maxbar;
}
int main()
{
	 ll t;
	cin>>t;
	vector<ll>ans(100001);
	ll k=0;
	while(t)
	{
	    string s;
		cin>>s;
		//scanf("%s",&s);
		ll n=s.length();
		ll dp[n];
		ll result=algo(s,n,dp);
		/*for(int i=0;i<n;i++)
            cout<<dp[i]<<"  ";*/
		ans[k]=result;
		k++;
		t--;
	}
	for(ll i=0;i<k;i++)
		cout<<ans[i]<<endl;
}
