# include <iostream>
# include <bits/stdc++.h>
typedef long long int ll;
//typedef long ll ls;
using namespace std;
struct node
{
    ll q;
    ll index;
};
bool compare(struct node x,struct node y)
{
    return (x.q<y.q);
}

ll l[300005];
ll c[300005];
ll p[300005];
ll cost[300005];
ll ans[300005];
ll sum[300005];
vector<struct node>queries(300005);
int main()
{
    //cout<<LONG_MAX;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin("journey2.txt");
	ll n,m;
	cin>>n>>m;
    ll sum=0;
	for(ll i=2;i<=n;i++)
	{	
        cin>>l[i];
        sum+=l[i];
        ans[i]=sum;
    }
	for(ll i=1;i<=n-1;i++)
		cin>>c[i];
	for(ll i=1;i<=n-1;i++)
		cin>>p[i];
    for(ll i=0;i<m;i++)
    {
        cin>>queries[i].q;
        queries[i].index=i;
    }
	/*for(ll i=2;i<=n-1;i++)
	{
		ll x=c[i];
		ll index=i+1;
		while(x>=0)
		{
			x=x-l[index];
			index++;
		}
		jump[i]=
	}*/
	cost[n]=0;
	for(ll i=n-1;i>=1;--i)
	{
        if(c[i]>=sum-ans[i])
            cost[i]=p[i];
        else
	    {
            ll mincost=LLONG_MAX;
    		ll x=c[i];
            ll index=i+1;
    		while(index>=1 && index<=n)
    		{
    			x=x-l[index];
    			if(x<0)
                    break;
                mincost=min(mincost,cost[index]);
    			index++;
    		}
            if(mincost==LLONG_MAX)
                cost[i]=LLONG_MAX;
            else
                cost[i]=mincost+p[i];
        }
	}
	/*for(ll i=1;i<=n;i++)
		cout<<cost[i]<<endl;
    cout<<endl;*/
    sort(queries.begin(),queries.begin()+m,compare);
    ll current_index=2;
    ll totaldecrease=0;
    ll mincost=LLONG_MAX;
    /*for(ll i=1;i<=m;i++)
        cout<<queries[i].q<<"  ";
    cout<<endl;*/
    for(ll i=0;i<m;i++)
    {
        ll x=(queries[i].q)-totaldecrease;
        //cout<<x<<"  ";
        mincost=min(mincost,cost[current_index-1]);
        while(current_index<=n)
        {
            x=x-l[current_index];
            if(x<0)
                break;
            totaldecrease=totaldecrease+l[current_index];
            mincost=min(mincost,cost[current_index]);
            current_index++;
        }
        //current_index--;
        /*if(current_index==1)
            current_index=2;*/
        //cout<<current_index<<endl;
        ans[queries[i].index]=mincost;
    }
    //cout<<endl;
    for(ll i=0;i<m;i++)
    {
        if(ans[i]==LLONG_MAX)
            cout<<"-1"<<"\n";
        else
            cout<<ans[i]<<"\n";
    }
}
