# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int mincost(int shirts[],int pants[],int shoes[],int dp[][3],int n)
{
	for(int i=0;i<=2;i++)
	{
		if(i==0)
			dp[0][i]=shirts[0];
		else if(i==1)
			dp[0][i]=pants[0];
		else
			dp[0][i]=shoes[0];
	}
	for(int k=1;k<n;k++)
	{
		for(int i=0;i<=2;i++)
		{
			if(i==0)
				dp[k][i]=min(dp[k-1][(i+1)%3],dp[k-1][(i+2)%3])+shirts[k];
			else if(i==1)
				dp[k][i]=min(dp[k-1][(i+1)%3],dp[k-1][(i+2)%3])+pants[k];
			else
				dp[k][i]=min(dp[k-1][(i+1)%3],dp[k-1][(i+2)%3])+shoes[k];
		}
	}
	return min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}
int main()
{
	int t;
	cin>>t;
	vector<int>myvector;
	while(t)
	{
		int n;
		cin>>n;
		int dp[n][3];
		int shirts[n],shoes[n],pants[n];
		for(int i=0;i<n;i++)
		{
			cin>>shirts[i]>>pants[i]>>shoes[i];

		}
		int result=mincost(shirts,pants,shoes,dp,n);
		/*for(int k=0;k<n;k++)
        {
            for(int i=0;i<=2;i++)
                cout<<dp[k][i]<<"  ";
            cout<<endl;
        }*/
		myvector.push_back(result);
		t--;
	}
	vector<int>::iterator itr=myvector.begin();
	while(itr!=myvector.end())
	{
		cout<<*itr<<endl;
		itr++;
	}
}
