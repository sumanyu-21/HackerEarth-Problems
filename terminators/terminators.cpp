# include <iostream>
using namespace std;
int algo(int day1[],int day2[],int **dp,int n)
{
	/*int lcs=0;
	dp[0][0]=day1[0]==day2[0]?1:0;
	lcs=dp[0][0];
	for(int i=1;i<n;i++)
	{
		if(day1[i]==day2[0])
			dp[i][0]=1;
		else
			dp[i][0]=dp[i-1][0];
		lcs=max(lcs,dp[i][0]);
	}
	for(int j=1;j<n;j++)
	{
		if(day2[j]==day1[0])
			dp[0][j]=1;
		else
			dp[0][j]=dp[0][j-1];
		lcs=max(lcs,dp[0][j]);
	}*/
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
		    if(i==0||j==0)
                dp[i][j]=0;
			else if(day1[i]==day2[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			//lcs=max(lcs,dp[i][j]);
		}
	}
	return dp[n][n];
}
int main()
{
	int t;
	cin>>t;
	int ans[105];
	int k=0;
	while(t)
	{
		int n,x,y;
		cin>>n;
		int day1[n+1],day2[n+1];
		int **dp;
		for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            day1[x]=day2[y]=i;
        }
		dp=new int*[n+1];
		for(int i=0;i<=n;i++)
			dp[i]=new int[n+1];
		int result=algo(day1,day2,dp,n);
		/*for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				cout<<dp[i][j]<<"  ";
			cout<<endl;
		}*/
        ans[k]=result;
		k++;
		t--;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
    return 0;
}
