# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int minprimatic(int **dp,vector<int>prime,int k, int n)
{
	int minprimatic=INT_MAX;
	for(int i=0;i<k;i++)
		dp[i][0]=INT_MAX;
	for(int j=1;j<=n;j++)
	{
			if(j%prime[0]==0)
				dp[0][j]=j/prime[0];
            else
                dp[0][j]=INT_MAX;
	}
	for(int i=1;i<k;i++)
	{
	    minprimatic=INT_MAX;
		for(int j=1;j<=n;j++)
        {
            if(j>=prime[i])
             {
                 //int minans=min(dp[i-1][j-prime[i]],dp[i-1][j]);
                 int a=dp[i][j-prime[i]];
                 int b=dp[i-1][j];
                 if(a==INT_MAX && b==INT_MAX)
                    dp[i][j]=INT_MAX;
                 else if(a==INT_MAX && b!=INT_MAX)
                    dp[i][j]=b;
                 else if(b==INT_MAX && a!=INT_MAX)
                    dp[i][j]=a+1;
                 else
                    dp[i][j]=min(a+1,b);
                if(j%prime[i]==0)
                    dp[i][j]=min(dp[i][j],j/prime[i]);
             }
            else
                dp[i][j]=dp[i-1][j];
        }

	}
	return dp[k-1][n];
}
int main()
{
	int t;
	cin>>t;
	int query[t];
	int ans[100001];
	int x=0;
	//while(t--)
	//{
	    int n=INT_MIN;
        for(int i=0;i<t;i++)
        {
            cin>>query[i];
            n=max(n,query[i]);
        }
		/*int n;
		cin>>n;*/
		//cout<<"working";
		int arr[n+1];
		//cout<<"working";
		for(int i=0;i<=n;i++)
			arr[i]=1;
		arr[0]=0;
		arr[1]=0;
		vector<int>prime(10000);
		for(int i=1;i<=sqrt(n);i++)
		{
			if(arr[i]==1)
			{
				for(int j=i;i*j<=n;j++)
					arr[i*j]=0;
			}
		}
		int primatic[100];
		int y=0;
		for(int i=2;(int)pow(i,i)<=n;i++)
		{
			if(arr[i]==1)
            {
                primatic[y]=(int)pow(i,i);
                y++;
            }
		}
		for(int i=0;i<y;i++)
            arr[primatic[i]]=1;
		int k=0;
		for(int i=0;i<=n;i++)
		{
			if(arr[i]==1)
			{
				prime[k]=i;
				k++;
			}

		}
		/*for(int i=0;i<k;i++)
           cout<<prime[i]<<"  ";
        cout<<endl;*/
		int **dp=new int *[k];
		for(int i=0;i<k;i++)
			dp[i]=new int [n+1];
		int result=minprimatic(dp,prime,k,n);
		//cout<<"working";
		for(int i=0;i<t;i++)
        {
            int j;
            for(j=0;j<k;j++)
            {
                if(prime[j]>query[i])
                {
                   // j--;
                    break;
                }
               /* else if(prime[j]=query[i])
                    break;*/
            }
           // cout<<prime[j-1];
            ans[x]=dp[j-1][query[i]];
            x++;
        }
		//ans[x]=result;
		//x++;
		/*for(int i=0;i<=n;i++)
            cout<<i<<"  ";
        cout<<endl;
		for(int i=0;i<k;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(dp[i][j]>=0 && dp[i][j]<INT_MAX)
                    cout<<dp[i][j]<<"  ";
                else
                    cout<<"0  ";
            }
            cout<<endl;
        }*/
	for(int i=0;i<x;i++)
		cout<<ans[i]<<endl;
}
