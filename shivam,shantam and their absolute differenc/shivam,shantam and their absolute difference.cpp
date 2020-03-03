# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define mod 1000000007;
int algo(int ***dp,int a[],int b[],int n,int suma,int sumb,int q)
{
	for(int i=0;i<=suma;i++)
	{
		for(int j=0;j<=sumb;j++)
		{
			if(i==a[1] && j==b[1])
				dp[1][i][j]=1;
			else if(i==a[1] && j==0)
				dp[1][i][j]=1;
			else if(i==0 && j==b[1])
				dp[1][i][j]=1;
			else
				dp[1][i][j]=0;
		}
	}
	for(int k=1;k<=n;k++)
		dp[k][0][0]=1;
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i<=suma;i++)
			{
				dp[k][i][0]=i-a[k]>=0?dp[k-1][i-a[k]][0]+dp[k-1][i][0]:dp[k-1][i][0];
			}
	}
	for(int k=2;k<=n;k++)
	{
		for(int j=1;j<=sumb;j++)
			{
				dp[k][0][j]=j-b[k]>=0?dp[k-1][0][j-b[k]]+dp[k-1][0][j]:dp[k-1][0][j];
			}
	}
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i<=suma;i++)
		{
			for(int j=1;j<=sumb;j++)
			{
				if(i-a[k]>=0 && j-b[k]>=0)
					dp[k][i][j]=dp[k-1][i-a[k]][j-b[k]]+dp[k-1][i-a[k]][j]+dp[k-1][i][j-b[k]]+dp[k-1][i][j];
				else if(i-a[k]>=0 && j-b[k]<0)
					dp[k][i][j]=dp[k-1][i-a[k]][j]+dp[k-1][i][j];
				else if(j-b[k]>=0 && i-a[k]<0)
					dp[k][i][j]=dp[k-1][i][j-b[k]]+dp[k-1][i][j];
                else
                    dp[k][i][j]=dp[k-1][i][j];
			}
		}
	}
	int counter =0;
	for(int i=0;i<=suma;i++)
	{
		for(int j=0;j<=sumb;j++)
		{
			if(abs(i-j)<=q)
				counter+=dp[n][i][j];
		}
	}
	return counter;
}
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n+1];
	int suma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		suma+=a[i];
	}
	int sumb=0;
	for(int j=1;j<=n;j++)
	{
		cin>>b[j];
		sumb+=b[j];
	}
	int q;
	cin>>q;
	int ***dp=new int **[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int*[suma+1];
		for(int j=0;j<=suma;j++)
			dp[i][j]=new int[sumb+1];
	}
	//cout<<"working"<<endl;
	int result=algo(dp,a,b,n,suma,sumb,q);
	/*for(int i=0;i<=suma;i++)
    {
        for(int j=0;j<=sumb;j++)
            cout<<dp[1][i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=suma;i++)
    {
        for(int j=0;j<=sumb;j++)
            cout<<dp[2][i][j]<<"  ";
        cout<<endl;
    }*/
	cout<<result;
}
