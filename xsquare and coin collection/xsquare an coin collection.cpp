# include <iostream>
# include <bits/stdc++.h>
using namespace std;
long long algo(long long arr[],long long n,long long k,long long dp[])
{
	long long maxcoin,index,sum=0;
	if(arr[0]<=k)
		dp[0]=arr[0];
	else
		dp[0]=0;
	maxcoin=dp[0];
	index=0;
	for(long long i=1;i<n;i++)
	{
		if(arr[i]<=k)
			dp[i]=dp[i-1]+arr[i];
		else
			dp[i]=0;
		/*if(dp[i]>maxcoin)
		{
			maxcoin=dp[i];
			index=i;
		}*/
		maxcoin=max(maxcoin,dp[i]);
	}
	/*while(maxcoin>0)
	{
        sum+=arr[index];
		index--;
		maxcoin--;

	}*/
	/*for(long long i=0;i<n;i++)
        cout<<dp[i]<<"  ";*/
	//return sum;
	return maxcoin;

}
int main()
{
	int t;
	cin>>t;
	long long v[100001];
	/*for(int i=0;i<=100000;i++)
        v[i]=-1;*/
    int j=0;
	while(t)
	{
		long long n,k;
		cin>>n>>k;
		long long arr[n],dp[n];
		for(long long i=0;i<n;i++)
			cin>>arr[i];
		long long result=algo(arr,n,k,dp);
		v[j]=result;
		//cout<<v[k];
		j++;
		t--;
	}
	/*vector<int>::iterator itr =v.begin();
	while(*itr!=-1)
	{
		cout<<*itr<<endl;
		itr++;
	}*/
	for(long long i=0;i<j;i++)
        cout<<v[i]<<endl;

}
