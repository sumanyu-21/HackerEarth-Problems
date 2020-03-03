# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int minrest(int arr[],int dp[][3],int n)
{
	if(arr[0]==0)
		dp[0][0]=1;
	else if(arr[0]==1)
		dp[0][1]=0;
	else if(arr[0]==2)
		dp[0][2]=0;
	else if(arr[0]==3)
	{
		dp[0][1]=0;
		dp[0][2]=0;
	}
	for(int i=1;i<n;i++)
	{
		if(arr[i]==0)
		{
			dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
		}
		else if(arr[i]==1)
		{
			if(dp[i-1][1]!=INT_MAX && dp[i-1][1]<dp[i-1][2])
				dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
			else if(dp[i-1][1]!=INT_MAX && dp[i-1][1]>dp[i-1][2])
			    dp[i][1]=dp[i-1][2];
			else
				dp[i][1]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		}
		else if(arr[i]==2)
		{
			if(dp[i-1][2]!=INT_MAX && dp[i-1][2]<dp[i-1][1])
				dp[i][0]=min(dp[i-1][2],dp[i-1][1])+1;
			else if(dp[i-1][2]!=INT_MAX && dp[i-1][2]>dp[i-1][1])
			    dp[i][2]=dp[i-1][1];
			else
				dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		}
		else
		{
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
	}
	return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);

}
int main()
{
	/*int t;
	cin>>t;*/
	std::vector<int> myvector(1000);
	/*while(t)
	{*/
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int dp[n][3];
		for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
                dp[i][j]=INT_MAX;
        }
		int result=minrest(arr,dp,n);
		cout<<result<<endl;
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
				cout<<dp[i][j]<<"  ";
			cout<<endl;
		}
		myvector.push_back(result);
		t--;
	}
	vector<int>::iterator itr=myvector.begin();
	while(itr!=myvector.end())
	{
		cout<<*itr<<endl;
		itr++;
	}*/
}

