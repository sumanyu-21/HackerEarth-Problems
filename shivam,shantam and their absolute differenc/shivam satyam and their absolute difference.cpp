# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define mod 1000000007;
int algo(int ***dp,int a[],int b[],int n,int q)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 && j==0)
				dp[1][i][j]=1;
			else if(i==0 && j==1)
				dp[1][i][j]=1;
			else if(j==0 && i==1)
				dp[1][i][j]=1;
            else if(i==1 && j==1)
                dp[1][i][j]=1;
			else
				dp[1][i][j]=0;

		}
	}
	for(int k=2;k<=n;k++)
		dp[k][0][0]=1;
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			dp[k][i][0]=dp[k-1][i-1][0];
	}
	for(int k=2;k<=n;k++)
	{
		for(int j=1;j<=n;j++)
			dp[k][0][j]=dp[k-1][0][j-1];
	}
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				dp[k][i][j]=dp[k-1][i-1][j-1]+dp[k-1][i-1][j]+dp[k-1][i][j-1];
		}

	}
	int sum=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(abs(a[i]-a[j])<=q)
				sum+=dp[n][i][j];
		}
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n+1];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		if(i!=1)
			a[i]=a[i-1]+c;
		else
			a[i]=c;
	}
	for(int j=1;j<=n;j++)
	{
		int c;
		cin>>c;
		if(j!=1)
			b[j]=b[j-1]+c;
		else
			b[j]=c;
	}
	int q;
	cin>>q;
	int ***dp=new int **[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int*[n+1];
		for(int j=0;j<=n;j++)
			dp[i][j]=new int[n+1];
	}
	//cout<<"working"<<endl;
	int result=algo(dp,a,b,n,q);
	cout<<result<<endl;
	/*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<dp[0][i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;*/
	for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<dp[1][i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
	for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<dp[2][i][j]<<"  ";
        cout<<endl;
    }
}
