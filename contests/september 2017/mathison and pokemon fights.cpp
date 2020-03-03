# include <iostream>
# include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	ll arr[2][n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[0][i]>>arr[1][i];
	while(q--)
	{
		int c;
		cin>>c;
		if(c==0)
		{
			int p;
			cin>>p;
			cin>>arr[0][p]>>arr[1][p];
		}
		else
		{
			int a,b;
			ll primary,secondary;
			cin>>a>>b;
			cin>>primary>>secondary;
			ll ans=0;
			for(int i=a;i<=b;i++)
			{
				ans+=max(abs(primary-arr[0][i]),abs(secondary-arr[1][i]));
			}
			cout<<ans<<endl;
		}
	}
}
