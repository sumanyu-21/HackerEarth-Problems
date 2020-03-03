# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int algo(int arr[],int dp[], int n)
{
	int maxresult=INT_MIN;
	if(n==0)
	{
		dp[n]=arr[n];
		return dp[n];
	}
	/*else if(n==1)
    {
        dp[n]=max(algo(arr,dp,n-1))
    }*/
	else if(n<0)
		return 0;
	else if(dp[n]==-1)
	{
		dp[n]=max(algo(arr,dp,n-2)+arr[n],algo(arr,dp,n-1));
		/*for(int k=2;k<=n+1;k++)
		{
			int result=algo(arr,dp,n-k)+arr[n];
			maxresult=max(result,maxresult);
		}
		int result=algo(arr,dp,n-1);
		maxresult=max(result,maxresult);
		dp[n]=maxresult;*/
	}
	return dp[n];
}
int main()
{
	int t;
	scanf("%d",&t);
	vector<int>save;
	while(t)
	{
	    int n;
		cin>>n;
		int arr[n],dp[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
			dp[i]=-1;
		/*for(int i=0;i<n;i++)
		{
			if(i%2==0)
				sumeven+=arr[i];
			else
				sumodd+=arr[i];
		}
		sum=max(sumeven,sumodd);*/
		int result=algo(arr,dp,n-1);
		save.push_back(result);
		t--;
		/*for(int i=0;i<n;i++)
            cout<<dp[i]<<"  ";
        cout<<endl;*/
	}
	int k=1;
	for(vector<int>::iterator i=save.begin();i!=save.end();i++)
    {
        cout<<"Case "<<k<<": "<<*i<<endl;
        k++;
    }
}
