# include <bits/stdc++.h>
# include <string>
using namespace std;
int numberofr(int dp[],int arr[],string s,int n)
{
    int maxr=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                if(s[i]=='R')
                    dp[j]=arr[n-1]-1;

                else
                    dp[j]=arr[n-1]+1;
            }
            else
            {
                if(s[j]=='K')
                    dp[j]=dp[j-1]+1;
                else
                    dp[j]=dp[j-1]-1;
            }
            maxr=max(maxr,dp[j]);
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
		int dp[n];
		int arr[n];
		arr[0]=s[0]=='R'?1:0;
		for(int i=1;i<n;i++)
        {
            if(s[i]=='R')
                arr[i]=arr[i-1]+1;
            else
                arr[i]=arr[i-1];
        }
		int result=numberofr(dp,arr,s,n);
        ans[k]=result;
		k++;
		t--;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;

}
