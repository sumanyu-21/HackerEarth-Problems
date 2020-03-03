# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int algo(int arr[],int n,int k,int dp[])
{
	int sum=0;
	for(int i=0;i<k;i++)
	{
		int flag=-1;
		int j=i+k;
		while(j<n && flag==-1)
		{
			if(arr[j]<arr[i])
				flag=1;
			j++;
		}
		if(flag==1)
			dp[i]=j-1-i;
		else
			dp[i]=0;
		sum+=dp[i];
	}
	for(int i=n-1;i>=n-k;i--)
	{
		if(dp[i]==-1)
		{
			int flag=-1;
			int j=i-k;
			while(j>=0 && flag==-1)
			{
				if(arr[j]<arr[i])
					flag=1;
				j--;
			}
			if(flag==1)
				dp[i]=i-j-1;
			else
				dp[i]=0;
		}
		sum+=dp[i];
	}
	for(int i=k;i<=n-k-1;i++)
	{
		int flag=-1;
		int l=i-k;
		int r=i+k;
		int minvaluel;
		int minvaluer;
		while(r<n && flag==-1)
		{
			if(arr[r]<arr[i])
				flag=1;
			r++;
		}
		if(flag==1)
			minvaluer=r-1-i;
		else
			minvaluer=INT_MAX;

        flag=-1;
		while(l>=0 && flag==-1)
		{
			if(arr[l]<arr[i])
				flag=1;
			l--;
		}
		if(flag==1)
			minvaluel=i-l-1;
		else
			minvaluel=INT_MAX;
		dp[i]=min(minvaluer,minvaluel)==INT_MAX?0:min(minvaluer,minvaluel);
		sum+=dp[i];
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	int ans[11];
	int index=0;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int dp[n];
		for(int i=0;i<n;i++)
			dp[i]=-1;
		int result=algo(arr,n,k,dp);
		/*for(int i=0;i<n;i++)
            cout<<dp[i]<<"  ";
        cout<<endl;*/
		ans[index]=result;
		index++;
	}
	for(int i=0;i<index;i++)
		cout<<ans[i]<<endl;
}
