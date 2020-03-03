# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int **dp=new int *[n];
	for(int i=0;i<n;i++)
		dp[i]=new int [n];
	int color[n];
	for(int i=0;i<n;i++)
		cin>>color[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<=i+1;j++)
		{
			if(i==j)
				dp[i][j]=1;
			else
			{
				if(color[i]==color[j])
					dp[i][j]=0;
				else
					dp[i][j]=2;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+2;j<n;j++)
		{
			int minvalue=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				minvalue=min(minvalue,dp[i][k]+dp[k+1][j]);
			}
			dp[i][j]=minvalue;
		}
	}
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<"  ";
        cout<<endl;
    }
	cout<<dp[0][n-1];
}
