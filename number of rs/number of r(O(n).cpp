# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ans[11];
	int k=0;
	while(t--)
	{
		string s;
		cin>>s;
		int totalr=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='R')
				totalr++;
		}
		int dp[s.length()];
		int maxans;
		if(s[0]=='R')
			dp[0]=totalr-1;
		else
			dp[0]=totalr+1;
		maxans=dp[0];
		for(int i=1;i<s.length();i++)
		{
			if(s[i]=='K'&& s[i-1]=='K')
				dp[i]=dp[i-1]+1;
			else if(s[i]=='K'&& s[i-1]=='R')
				dp[i]=max(dp[i-1]+1,totalr+1);
			else if(s[i]=='R')
				dp[i]=max(dp[i-1]-1,totalr-1);
			maxans=max(maxans,dp[i]);
		}
		/*for(int i=0;i<s.length();i++)
            cout<<dp[i]<<"  ";
        cout<<endl;*/
		ans[k]=maxans;
		k++;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;

}
