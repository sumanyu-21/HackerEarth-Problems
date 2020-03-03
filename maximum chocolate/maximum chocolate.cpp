# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int  main()
 {
 	ll n;
 	cin>>n;
 	ll arr[n][n];
 	for(ll i=0;i<n;i++)
 	{
 		for(ll j=0;j<n;j++)
 			cin>>arr[i][j];
 	}
 	ll dp[n][n];
 	ll result=-1;
 	for(ll j=0;j<n;j++)
 	{
 		dp[0][j]=arr[0][j];
 		result=max(dp[0][j],result);
 	}
 	for(ll i=1;i<n;i++)
 	{
 		for(ll j=0;j<n;j++)
 		{
 			if(j==0)
 				dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+arr[i][j];
 			else if(j==n-1)
 				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
 			else
 				dp[i][j]=max(max(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1])+arr[i][j];
            result=max(result,dp[i][j]);
 		}

 	}
 	/*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<"  ";
        cout<<endl;
    }*/
 	cout<<result;
 }
