# include <bits/stdc++.h>
# include <string>
using namespace std;
int numberofr(int **dp,int arr[],string s,int n)
{
    int maxr=0;
	for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
            dp[i][i]=arr[n-1]-1;

        else
            dp[i][i]=arr[n-1]+1;
        maxr=max(maxr,dp[i][i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[j]=='K')
                dp[i][j]=dp[i][j-1]+1;
            else
                dp[i][j]=dp[i][j-1]-1;
            maxr=max(maxr,dp[i][j]);
        }
    }
    return maxr;

}
int main()
{
	int t;
	cin>>t;
	int ans[11];
	int k=0;
	while(t)
	{
		string s;
		cin>>s;
		int n=s.length();
		int **dp=new int*[n];
		int arr[n];
		arr[0]=s[0]=='R'?1:0;
		for(int i=1;i<n;i++)
        {
            if(s[i]=='R')
                arr[i]=arr[i-1]+1;
            else
                arr[i]=arr[i-1];
        }
        for(int i=0;i<n;i++)
		{
			dp[i]=new int[n];
		}
		int result=numberofr(dp,arr,s,n);
		for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
              cout<<dp[i][j]<<"  ";
            cout<<endl;
        }

		ans[k]=result;
		k++;
		t--;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;

}
