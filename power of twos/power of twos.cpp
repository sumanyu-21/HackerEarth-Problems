# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ans[10001];
	int k=0;
	vector<int>divisible(1000001,1);
	divisible[0]=0,divisible[1]=0;
	for(int i=2;i<=1000000;i++)
	{
		for(int j=2;j*i<=1000000;j++)
			divisible[i*j]++;
	}
	vector<int>dp(1000001);
	dp[1]=0;
	for(int i=2;i<=1000000;i++)
		dp[i]=dp[i-1]+divisible[i];
	while(t--)
	{
		int n;
		cin>>n;
		ans[k]=dp[n];
		k++;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
}
