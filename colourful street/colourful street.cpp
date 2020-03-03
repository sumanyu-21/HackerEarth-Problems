# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int algo(int arr[][3],int dp[][3],int n)
{
	dp[0][0]=arr[0][0],dp[0][1]=arr[0][1],dp[0][2]=arr[0][2];
	for(int i=1;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
		dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
	}
	return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}
int main()
{
	int t;
	cin>>t;
	int *ans=new int[1000000];
	int k=0;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n][3],dp[n][3];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
				cin>>arr[i][j];
		}
		int result=algo(arr,dp,n);
		ans[k]=result;
		k++;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
}
