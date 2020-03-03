# include <bits/stdc++.h>
using namespace std;
int algo(int arr[],int n,int dp[])
{
	/*int mintablet=INT_MAX,maxtablet=INT_MIN;
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
        {
            if(dp[i-1]<=1)
                dp[i]=dp[i-1]-1;
            else
                dp[i]=1;
        }
		else if(arr[i]>arr[i-1])
			dp[i]=dp[i-1]+1;
		else
        {   if(dp[i-1]<0)
                dp[i]=dp[i-1];
            else
                dp[i]=1;
        }
		mintablet=min(mintablet,dp[i]);
		maxtablet=max(maxtablet,dp[i]);
	}
	for(int i=0;i<n;i++)
        cout<<dp[i]<<"  ";
    cout<<endl;
	int sum=0;
	if(mintablet<0)
    {
        for(int i=0;i<n;i++)
        {
            dp[i]=dp[i]-mintablet+1;
            cout<<dp[i]<<"  ";
            sum+=dp[i];
        }
        return sum;
    }
	else
	{
	    for(int i=0;i<n;i++){cout<<dp[i]<<"  ";
            sum+=dp[i];}
        return sum;
	}
*/
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            dp[i]=dp[i-1]+dp[i];
        }
    }
    /*for(int i=0;i<n;i++)
        cout<<dp[i]<<"  ";
    cout<<endl;*/
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1] && dp[i]<=dp[i+1])
            dp[i]+=dp[i+1];
    }
    /*for(int i=0;i<n;i++)
        cout<<dp[i]<<"  ";
    cout<<endl;*/
    int sum=0;
    for(int i=0;i<n;i++)
            sum+=dp[i];
    return sum;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int dp[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int result=algo(arr,n,dp);
	cout<<result<<endl;
}
