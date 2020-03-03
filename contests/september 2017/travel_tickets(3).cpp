# include <iostream>
# include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct c1
{
    ll cost;
    ll gain;
};
struct c2
{
    ll usteps;
    ll dsteps;
};
struct node
{
	ll forwardcost;
	ll forwardgain;
    ll backwardcost;
    ll backwardgain;
	ll x;
};
ll table[300001][20];
ll sparse[300001][20][4];
ll depth[300001];
ll D;
bool mark[300001];

vector<list<struct node> >adj(300001);


void dfs(ll s)
{
    mark[s]=true;
	for(auto p:adj[s])
	{
	    if(!mark[p.x])
		{
		    depth[p.x]=depth[s]+1;
		    table[p.x][0]=s;
            sparse[p.x][0][0]=p.backwardcost;
           sparse[p.x][0][1]=p.backwardgain;
           sparse[p.x][0][2]=p.forwardcost;
           sparse[p.x][0][3]=p.forwardgain;
            dfs(p.x);
		}
	}
}
ll walk(ll i,ll k)
{
    for(ll d=0;d<=D && i!=-1;d++)
        if(((1<<d)&k)>0)
        {
            if(table[i][d]==-1)
                break;
            else
                i=table[i][d];
        }
    return i;
}
struct c1 walkup(ll i,ll k)
{
    ll totalgain=0,totalcost=0;
    for(ll d=0;d<=D && i!=-1;d++)
    {
        if(((1<<d)&k)>0)
        {
            ll currentcost=sparse[i][d][0];
            ll currentgain=sparse[i][d][1];
            i=table[i][d];
            if(i!=-1 && totalgain>=currentcost)
            {
                totalgain=totalgain-currentcost+currentgain;
            }
            else if(i!=-1 && totalgain<currentcost)
            {
                totalcost=totalcost+currentcost-totalgain;
                totalgain=currentgain;
            }

        }
    }
    struct c1 temp;
    temp.cost=totalcost;
    temp.gain=totalgain;
    //cout<<totalcost<<"  "<<totalgain<<endl;
    return temp;
}

struct c1 walkdown(ll i,ll k)
{
    ll totalcost=0;
    ll totalgain=0;
    for(ll d=0;d<=D && i!=-1;d++)
    {
        if(((1<<d)&k)>0)
        {
            ll currentcost=sparse[i][d][2];
            ll currentgain=sparse[i][d][3];
            i=table[i][d];
            if(i!=-1 && currentgain>=totalcost)
            {
                totalgain=totalgain+currentgain-totalcost;
                totalcost=currentcost;
            }
            else if(i!=-1 && currentgain<totalcost)
            {
                totalcost=currentcost+totalcost-currentgain;
            }
        }
    }
    struct c1 temp;
    temp.cost=totalcost;
    temp.gain=totalgain;
    //cout<<totalcost<<"  "<<totalgain<<endl;
    return temp;
}
struct c2 lca(ll i,ll j)
{
    ll upsteps=0;
    ll downsteps=0;
    if(depth[i]>depth[j])
    {
        upsteps=depth[i]-depth[j];
        i=walk(i,depth[i]-depth[j]);
    }
    else if(depth[j]>depth[i])
    {
        downsteps=depth[j]-depth[i];
        j=walk(j,depth[j]-depth[i]);
        //cout<<j<<endl;
    }
    //cout<<depth[i]-depth[j]<<endl;
    //cout<<upsteps<<downsteps<<endl;
    if(i==j)
    {
        struct c2 temp;
        temp.usteps=upsteps;
        temp.dsteps=downsteps;
        return temp;
    }
    for(ll d=D;d>=0;d--)
    {
        if(table[i][d]!=table[j][d])
        {
            //cout<<"executing"<<endl;
            upsteps+=(1<<d);
            downsteps+=(1<<d);
            i=table[i][d];
            j=table[j][d];
        }
    }
    upsteps+=1;
    downsteps+=1;
    struct c2 temp;
    temp.usteps=upsteps;
    temp.dsteps=downsteps;
    return temp;
}

int main()
{
    //ifstream fin("traveltickets.txt");
	ll n,m;
	cin>>n>>m;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
		cin>>arr[i];
    depth[1]=1;
    D=log2(n+1)+1;
    for(ll i=0;i<=n;i++)
    {
        for(ll k=0;k<=D;k++)
        {
            table[i][k]=-1;
            sparse[i][k][0]=-1;
            sparse[i][k][1]=-1;
            sparse[i][k][2]=-1;
            sparse[i][k][3]=-1;
        }
    }
	for(ll i=1;i<=n-1;i++)
	{
		ll a,b,g;
		cin>>a>>b>>g;
		//table[b][0]=a;
		struct node temp,temp1;
		temp.x=b;
		temp1.x=a;
		if((g-arr[b])<=0)
		{
				temp.forwardgain=0;
				temp.forwardcost=arr[b]-g;
				temp1.backwardgain=0;
				temp1.backwardcost=arr[b]-g;
		}
		else
		{
			temp.forwardgain=g-arr[b];
			temp.forwardcost=0;
			temp1.backwardgain=g-arr[b];
			temp1.backwardcost=0;
		}
        if((g-arr[a])<=0)
		{
				temp.backwardgain=0;
				temp.backwardcost=arr[a]-g;
				temp1.forwardgain=0;
				temp1.forwardcost=arr[a]-g;
		}
		else
		{
			temp.backwardgain=g-arr[a];
			temp.backwardcost=0;
			temp1.forwardgain=g-arr[a];
			temp1.forwardcost=0;
		}
       adj[a].push_back(temp);
       adj[b].push_back(temp1);
    }
    dfs(1);
    for(ll k=1;k<=D;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            ll mid=table[i][k-1];
            if(mid!=-1)
                table[i][k]=table[mid][k-1];
        }
    }
    for(ll k=1;k<=D;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            ll midcost=sparse[i][k-1][0];
            ll midgain=sparse[i][k-1][1];
            ll mid=table[i][k-1];
            if(mid!=-1)
            {
                ll nextcost=sparse[mid][k-1][0];
                ll nextgain=sparse[mid][k-1][1];
                if(nextcost!=-1 && midgain>=nextcost)
                {
                    sparse[i][k][0]=midcost;
                    sparse[i][k][1]=midgain-nextcost+nextgain;
                }
                else if(nextcost!=-1 && midgain<nextcost)
                {
                    sparse[i][k][0]=midcost+nextcost-midgain;
                    sparse[i][k][1]=nextgain;
                }
                else
                {
                    sparse[i][k][0]=-1;
                    sparse[i][k][1]=-1;
                }

            }
        }
    }
    for(ll k=1;k<=D;k++)
    {
        for(ll i=1;i<=n;i++)
        {
                ll mid=table[i][k-1];
                if(mid!=-1)
                {
                    ll midcost=sparse[mid][k-1][2];
                    ll midgain=sparse[mid][k-1][3];
                    //llcurrent=table[mid][k-1];
                    ll nextcost=sparse[i][k-1][2];
                    ll nextgain=sparse[i][k-1][3];
                    //if(current!=-1)
                    //{
                        if(midcost!=-1 && midgain>=nextcost)
                        {
                            sparse[i][k][2]=midcost;
                            sparse[i][k][3]=midgain-nextcost+nextgain;
                        }
                        else if(midcost!=-1 && midgain<nextcost)
                        {
                            sparse[i][k][2]=midcost+nextcost-midgain;
                            sparse[i][k][3]=nextgain;
                        }
                        else
                        {
                            sparse[i][k][2]=-1;
                            sparse[i][k][3]=-1;
                        }
                    }
        }
    }
    /*for(lli=1;i<=n;i++)
    {
        for(llj=0;j<=D;j++)
            cout<<table[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    for(lli=1;i<=n;i++)
    {
        for(llj=0;j<=D;j++)
            cout<<sparse[i][j][0]<<":"<<sparse[i][j][1]<<"  "<<sparse[i][j][2]<<":"<<sparse[i][j][3]<<"     ";
        cout<<endl;
    }*/
    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        ll tickets;
        struct c2 temp=lca(u,v);
        //cout<<temp.usteps;
        //cout<<temp.dsteps;
        //cout<<endl;
        struct c1 x=walkup(u,temp.usteps);
        struct c1 y=walkdown(v,temp.dsteps);
        ll upcost=x.cost;
        ll upgain=x.gain;
        ll downcost=y.cost;
        ll downgain=y.gain;
        //cout<<upcost<<"  "<<upgain<<endl;
        //cout<<downcost<<"  "<<downgain<<endl;
        if(upgain>=downcost)
            tickets=upcost;
        else
            tickets=upcost+downcost-upgain;
        cout<<tickets+arr[u]<<endl;

    }
}
