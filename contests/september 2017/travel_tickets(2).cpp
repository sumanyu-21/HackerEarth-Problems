# include <iostream>
# include <bits/stdc++.h>
using namespace std;
struct node
{
	int cost;
	int gain;
	int x;
};
//int tableto[300001][22];
//int tablefrom[300001][22];
int table[300001][22];
int from[300001][22][2];
int to[300001][22][2];
int depth[300001];
vector<list<struct node> >adj(300001);


void dfs(int s)
{
    cout<<"working"<<endl;
	for(auto p:adj[s])
	{
		if((p.x)!=table[s][0])
		{
			depth[p.x]=depth[s]+1;
			dfs(p.x);
		}
	}
}
int main()
{
    ifstream fin("traveltickets.txt");
	int n,m;
	fin>>n>>m;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		fin>>arr[i];
    depth[1]=1;
    //tablefrom[1][0]=-1;
    int d=log2(n)+1;
    for(int i=0;i<=n;i++)
    {
        for(int k=0;k<=d;k++)
        {
            //tableto[i][k]=-1;
            //tablefrom[i][k]=-1;
            table[i][k]=-1;
            from[i][k][0]=-1;
            from[i][k][1]=-1;
            to[i][k][0]=-1;
            to[i][k][1]=-1;
        }
    }
	for(int i=1;i<=n-1;i++)
	{
		int a,b,g;
		fin>>a>>b>>g;
		//tableto[a][0]=b;
		//tablefrom[b][0]=a;
		table[b][0]=a;
		struct node temp;
		temp.x=b;
		if((g-arr[b])<0)
		{
				temp.gain=0;
				temp.cost=arr[b]-g;
		}
		else
		{
			temp.gain=g-arr[b];
			temp.cost=0;
		}
		to[a][0][0]=temp.cost;
		to[a][0][1]=temp.gain;
		cout<<to[a][0][0]<<":"<<to[a][0][1]<<endl;
		adj[a].push_back(temp);

		struct node temp2;
		temp2.x=a;
		if((g-arr[a])<0)
		{
				temp2.gain=0;
				temp2.cost=arr[a]-g;
		}
		else
		{
			temp2.gain=g-arr[a];
			temp2.cost=0;
		}
		from[b][0][0]=temp2.cost;
		from[b][0][1]=temp2.gain;
		cout<<from[b][0][0]<<":"<<from[b][0][1]<<endl;
		adj[b].push_back(temp2);
    }
    dfs(1);
    for(int k=1;k<=d;k++)
    {
        for(int i=1;i<=n;i++)
        {
            int mid=table[i][k-1];
            if(mid!=-1)
                table[i][k]=table[mid][k-1];
            /*mid=tablefrom[i][k-1];
            if(mid!=-1)
                tablefrom[i][k]=tablefrom[mid][k-1];*/
        }
    }
    /*for(int k=1;k<=d;k++)
    {
        for(int i=1;i<=n;i++)
        {
            int midcost=from[i][k-1][0];
            int midgain=from[i][k-1][1];
            int mid=table[i][k-1];
            if(mid!=-1)
            {
                int nextgain=from[mid][k-1][0];
                int nextcost=from[mid][k-1][1];
                if(nextcost!=-1 && midgain>=nextcost)
                {
                    from[i][k][0]=midcost;
                    from[i][k][1]=midgain-nextcost+nextgain;
                }
                else if(nextcost!=-1 && midgain<nextcost)
                {
                    from[i][k][0]=midcost+nextcost-midgain;
                    from[i][k][1]=nextgain;
                }
                else
                {
                    from[i][k][0]=-1;
                    from[i][k][1]=-1;
                }
                nextcost=to[mid][k-1][0];
                nextgain=to[mid][k-1][0];
                int current=table[mid][k-1];
                midcost=to[current][k-1][0];
                midgain=to[current][k-1][1];
                if(current!=-1)
                {
                    if(nextcost!=-1 && midgain>=nextcost)
                    {
                        to[i][k][0]=midcost;
                        to[i][k][1]=midgain-nextcost+nextgain;
                    }
                    else if(nextcost!=-1 && midgain<nextcost)
                    {
                        to[i][k][0]=midcost+nextcost-midgain;
                        to[i][k][1]=nextgain;
                    }
                    else
                    {
                        to[i][k][0]=-1;
                        to[i][k][1]=-1;
                    }
                }
            }
        }
    }*/
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=d;j++)
            cout<<table[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=d;j++)
            cout<<to[i][j][0]<<":"<<to[i][j][1]<<"   ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=d;j++)
            cout<<from[i][j][0]<<":"<<from[i][j][1]<<"   ";
        cout<<endl;
    }
}
