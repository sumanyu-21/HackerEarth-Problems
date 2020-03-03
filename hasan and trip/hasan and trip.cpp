# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	//cout<<pow(3.1456766,2);
	int x[n],y[n],f[n];
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i]>>f[i];
	double dp[n];
	dp[0]=f[0];
	double result;
	double d;
	double maxhappiness=INT_MIN;
	for(int i=1;i<n;i++)
	{
        result=INT_MIN;
		for(int j=i-1;j>=0;j--)
		{
            d=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
			if(result<dp[j]+f[i]-d)
			{
				result=dp[j]+f[i]-d;
				dp[i]=result;
			}
			//cout<<result<<endl;
		}
		maxhappiness=fmax(maxhappiness,dp[i]);
	}
	/*for(int i=0;i<n;i++)
        cout<<dp[i]<<"  ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<distance[i]<<"  ";
    cout<<endl;*/
	cout<<fixed<<setprecision(6)<<dp[n-1];
}
