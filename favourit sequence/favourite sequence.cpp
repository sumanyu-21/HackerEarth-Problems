# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll  mod=1000000007;
ll algo(string s,ll **dp,ll n)
{
    ll newans;
	ll index;
	ll ans;
	int flag=-1;
	for(index=0;index<n;index++)
	{
		if(s[index]=='a')
		{
		    flag=1;
		    break;
		}
	}
	if(flag==1)
	{
	    dp[index][0]=1,dp[index][1]=0,dp[index][2]=0;
        for(ll i=index+1;i<n;i++)
        {
                if(s[i]=='a')
                {
                    dp[i][0]=((2*dp[i-1][0]+1))%mod;
                    dp[i][1]=dp[i-1][1]%mod;
                    dp[i][2]=dp[i-1][2]%mod;
                }
                else if(s[i]=='b')
                {
                    dp[i][0]=dp[i-1][0]%mod;
                    dp[i][1]=(dp[i-1][0]+(2*dp[i-1][1]))%mod;
                    dp[i][2]=dp[i-1][2]%mod;
                }
                else if(s[i]=='c')
                {
                    dp[i][0]=dp[i-1][0]%mod;
                    dp[i][1]=dp[i-1][1]%mod;
                    dp[i][2]=(dp[i-1][1]+(2*dp[i-1][2]))%mod;
                    newans=dp[i][2];
                }
        }
	}
	return flag==1?dp[n-1][2]:0;

}

int main()
{
	string s;
	cin>>s;
	ll n=s.length();
	ll **dp=new ll*[n];
	for(ll i=0;i<n;i++)
		dp[i]=new ll[3];
	ll result =algo(s,dp,n);
	/*for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cout<<dp[i][j]<<"  ";
        cout<<endl;
    }*/

	cout<<result<<endl;
}
