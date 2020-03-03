# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int minpages(int sum,int dp[])
{
	int minvalue;
	for(int i=1;i<=12;i++)
		dp[i]=INT_MAX;
	dp[10]=1;
	dp[12]=1;
	for(int i=13;i<=sum;i++)
	{
		minvalue=min(dp[i-10],dp[i-12]);
		if(minvalue!=INT_MAX)
			dp[i]=minvalue+1;
		else
			dp[i]=INT_MAX;
	}
	return dp[sum]!=INT_MAX?dp[sum]:-1;
}
int main()
{
	int t;
	cin>>t;
	int ans[101];
	int k=0;
	while(t)
	{
	    int sum;
		cin>>sum;
		int dp[sum+1];
		int result=minpages(sum,dp);
		/*for(int i=1;i<=sum;i++)
            cout<<i<<"  "<<dp[i]<<endl;*/
		ans[k]=result;
		k++;
		t--;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;

}
