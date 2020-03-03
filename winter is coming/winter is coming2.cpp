# include <iostream>
# include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll k=0;
ll algo(ll arr[],ll n,ll ans[])
{
    ll minvalue,startingindex,index;
	for(ll i=0;i<n;i++)
	{
		ll sum=0;
		ll j=i;
		ll flag=-1;
		while(j>=0 && flag==-1)
		{
			sum+=arr[j];
			if(sum%n==0)
            {
                flag=1;
                break;
            }
            j--;
		}
		//cout<<flag<<endl;
		if(flag==1)
		{
		    minvalue=i-j+1;
		    //cout<<minvalue<<endl;
            startingindex=j;
            //cout<<startingindex<<endl;
            index=i;
            break;
		}
	}
		for(ll i=index+1;i<n;i++)
		{
			ll sum=0;
			ll j=i;
			ll flag=-1;
			ll counter=0;
			while(counter<=minvalue && flag==-1)
			{
				counter++;
				sum+=arr[j];
				if(sum%n==0)
                {
                    flag=1;
                    break;
                }
                j--;
			}
			if(flag==1 && counter<minvalue)
			{
				minvalue=counter;
				startingindex=j;
			}
		}

        ans[k]=startingindex+1;
		k++;
		ans[k]=startingindex+minvalue;
		k++;
	return 0;
}
 int main()
 {
 		ll t;
 		cin>>t;
 		ll ans[22];
 		while(t--)
 		{
 			ll n;
 			cin>>n;
 			ll arr[n];
 			for(ll i=0;i<n;i++)
 				cin>>arr[i];
 			algo(arr,n,ans);
 		}
 		for(ll i=0;i<k;i=i+2)
 			cout<<ans[i]<<" "<<ans[i+1]<<endl;
 }
