# include <iostream>
# include <bits/stdc++.h>
typedef  unsigned long long  ll;
using namespace std;

ll binomial(int n,int k)
{
    ll ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}
float win(int g, int r)
{
	if(r==0)
		return 1;
	//int n=g/2+1;
	ll result=0;
	for(int i=0;i<=g;i=i+2)
	{
	    result+=binomial(g+r-i-1,r-1);
	}
	ll totalways=binomial(g+r,r);
    /*cout<<result<<endl;
    cout<<totalways<<endl;*/
	float ans=(float)result/totalways;
	//cout<<ans<<endl;
	//cout<<ans<<endl;
	return ans;
}
int main()
{
	int t;
	cin>>t;
	float ans[11];
	int k=0;
	while(t)
	{
		int r,g;
		cin>>r>>g;
		float result=win(g,r);
		ans[k]=result;
		k++;
		t--;
	}
	for(int i=0;i<k;i++)
		printf("%.6f\n",ans[i]);
}
