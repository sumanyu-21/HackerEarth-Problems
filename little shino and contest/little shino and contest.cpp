# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	int totaltime=0;
	int maxai=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		totaltime+=a[i];
		maxai=max(maxai,a[i]);
	}
	maxbi=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x>arr[i])
			b[i]=arr[i];
		else
			b[i]=x;
		maxbi=max(maxbi,b[i]);
	}

	int dp[totaltime+1][n][maxbi+1][maxai+1];
	


}