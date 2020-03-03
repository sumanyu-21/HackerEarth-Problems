# include <iostream>
# include <bits/stdc++.h>
//typedef unsigned long long int ll;
using namespace std;
int algo(string s,int n,int **dp)
{
	int  minvalue;
	for(int i=0;i<n;i++)
	{
		dp[i][i]=INT_MAX;
		if(i!=n-1)
            dp[i][i+1]=s[i]==s[i+1]?1:INT_MAX;
	}

	for(int j=2;j<n;j++)
	{
		for(int i=j-2;i>=0;i--)
		{
            minvalue=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				if(dp[i][k]!=INT_MAX && dp[k+1][j]!=INT_MAX)
					minvalue=min(minvalue,dp[i][k]+dp[k+1][j]+1);
			}
			dp[i][j]=minvalue;
		}
	}
	return dp[0][n-1];
}
int main()
{
	int t;
	cin>>t;
	int ans[100005];
	int k=0;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		int result;
		if(n%2==0)
		{
			/*int **dp= new int *[n];
			for(int i=0;i<n;i++)
				dp[i]=new int[n];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					dp[i][j]=0;
			}
			cout<<"working"<<endl;
            result=algo(s,n,dp);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<dp[i][j]<<"  ";
				cout<<endl;
			}*/
            int arr[26];
            for(int i=0;i<26;i++)
                arr[i]=0;
            for(int i=0;i<n;i++)
                arr[((int)s[i])-97]++;
            int flag=1;
            for(int i=0;i<26;i++)
            {
                if(arr[i]%2!=0)
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==1)
                result=1;
            else
                result=-1;

        }
		else
            result =-1;
		ans[k]=result;
		k++;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
}
