# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int algo(int dp[][3],string s,int n)
{
    int maxvalue,maxfinal;;
	dp[0][0]=1,dp[0][1]=0,dp[0][2]=0;
	dp[1][0]=1,dp[1][1]=2,dp[1][2]=0;
	dp[2][0]=1,dp[2][1]=2;
	if(s[2]==s[1] && s[2]==s[0])
		dp[2][2]=0;
	else
		dp[2][2]=3;
    //maxvalue=dp[2][2];
    maxfinal=dp[2][2];
	for(int i=3;i<n;i++)
	{

		if(s[i]==s[i-1] && s[i]==s[i-2])
		{
			dp[i][0]=dp[i-1][2]+1;
			dp[i][1]=dp[i-1][0]+1;
			dp[i][2]=0;

		}
		else
		{
			dp[i][0]=dp[i-1][2]+1;
			dp[i][1]=dp[i-1][0]+1;
			dp[i][2]=dp[i-1][1]+1;
		}
		maxvalue=max(max(dp[i][0],dp[i][1]),dp[i][2]);
		maxfinal=max(maxfinal,maxvalue);
	}
	//cout<<maxvalue<<endl;
	//return n-max(max((dp[n-1][0]-dp[n-1][0]%3),(dp[n-1][1]-dp[n-1][1]%3)),(dp[n-1][2]-dp[n-1][2]%3));
	return (n-(maxfinal-maxfinal%3));
}
int main()
{
		int t;
		cin>>t;
		int ans[100005];
		int k=0;
		while(t>0)
		{
			string s;
			cin>>s;
			int n=s.length();
			int dp[n][3];
			int result=algo(dp,s,n);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<3;j++)
					cout<<dp[i][j]<<"  ";
				cout<<endl;
			}
			ans[k]=result;
			k++;
			t--;
		}
		for(int i=0;i<k;i++)
			cout<<ans[i]<<endl;
}
