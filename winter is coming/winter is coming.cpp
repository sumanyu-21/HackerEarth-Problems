# include <iostream>
# include <bits/stdc++.h>
typedef unsigned long long  ll;
using namespace std;
ll k=0;
ll algo(ll arr[],ll dp[],ll n,ll ans[],ll given[])
{
    ll minvalue;
	ll flag=-1;
	ll index,startingindex;
	for(ll i=1;i<n;i++)
	{
	    //cout<<"executing"<<endl;
		ll sum=0;
		ll j=i;
		while(j>=0)
		{
		    /*if(i==j && arr[i]%n==0)
            {
                flag=2;
				break;
            }*/
            if((arr[i]-arr[j]+given[j])%n==0)
			{
				flag=1;
				break;
			}
			j--;
		}
		//cout<<flag<<endl;
		if(flag==1)//||flag==2)
		{
		    //cout<<"done"<<endl;
		    //cout<<i<<"  "<<j<<endl;
			dp[i]=flag==1?i-j+1:i+1;
			//cout<<dp[i]<<endl;
			minvalue=dp[i];
			index=i;
			startingindex=flag==1?j:0;
			break;
		}
		/*else if(flag==2)
        {
            cout<<"done"<<endl;
		   // cout<<i<<"  "<<j<<endl;
			dp[i]=i+1;
			cout<<dp[i]<<endl;
			minvalue=dp[i];
			index=i;
			startingindex=0;
			break;
        }*/
	}
	for(ll i=0;i<index;i++)
		dp[i]=0;
	for(ll i=index+1;i<n;i++)
	{
        flag=-1;
		ll j=i;
		ll counter =0;
		while(counter<=minvalue)
		{
           /* if(i==j && arr[i]%n==0)
            {
                flag=2;
                break;
            }*/
			if((arr[i]-arr[j]+given[j])%n==0)
			{
				counter++;
				flag=1;
				break;
			}
			counter++;
		}
		if(flag==1)
		{
			dp[i]=counter;
			minvalue=dp[i];
			startingindex=j;
		}
		/*else if(flag==2)
        {
            //cout<<"done"<<endl;
		   // cout<<i<<"  "<<j<<endl;
			dp[i]=i+1;
			cout<<dp[i]<<endl;
			minvalue=dp[i];
			index=i;
			startingindex=0;
			break;
        }*/
		else
		{
			dp[i]=dp[i-1];
		}

	}
	ans[k]=startingindex+1;
	k++;
	ans[k]=startingindex+minvalue;
	k++;
	/*for(ll i=0;i<n;i++)
            cout<<dp[i]<<"  ";
        cout<<endl;*/
	return 0;

}
int main()
{
	ll t;
	cin>>t;
	ll ans[24];
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n],given[n];
		ll sum=0;
		ll c;
		for(ll i=0;i<n;i++)
		{

			cin>>given[i];
			 sum=sum+given[i];
			arr[i]=sum;

		}
		/*for(ll i=0;i<n;i++)
            cout<<arr[i]<<"  ";
        cout<<endl;*/
		ll dp[n];
		algo(arr,dp,n,ans,given);

	}
	for(ll i=0;i<k;i=i+2)
		cout<<ans[i]<<" "<<ans[i+1]<<endl;

}
