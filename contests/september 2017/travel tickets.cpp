# include <iostream>
# include <bits/stdc++.h>
using namespace std;
struct path
{
	int u;
	int v;
	int id;
};
struct node
{
	int x;
	int gain;
	int cost;
};
vector<list<struct node> >adj(300002);
int ans[300002];
//int counter[n+1];
int ctr;
int ctrcheck;
unordered_map<int,int>mymap;

bool compare(struct path x,struct path y)
{
   return (x.u<y.u);
}

void dfs(int s,int totalgain,int totalcost,int parent)
{

	if(mymap.find(s)!=mymap.end())
	{
		ans[mymap.find(s)->second]=totalcost;
		ctrcheck++;
	}

	for(auto p:adj[s])
	{
		if(ctrcheck==ctr)
			continue;
		if(p.x!=parent)
		{
			int nextgain=p.gain;
			int nextcost=p.cost;
			if(totalgain>=nextcost)
			{

				dfs(p.x,totalgain-nextcost+nextgain,totalcost,s);
			}
			else
			{
				dfs(p.x,nextgain,totalcost+nextcost-totalgain,s);
			}
		}
	}
}
int main()
{
    ifstream fin("traveltickets.txt");
	int n,m;
	fin>>n>>m;
	int arr[n+1];
	//fill(counter,counter+n+1,0);
	vector<struct path>queries(m+1);
	for(int i=1;i<=n;i++)
		fin>>arr[i];
	for(int i=1;i<=n-1;i++)
	{
		int a,b,g;
		fin>>a>>b>>g;
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
		adj[b].push_back(temp2);
		//counter[a]++;
		//counter[b]++;
    }
	/*for(int i=1;i<=n;i++)
	{
        cout<<i<<endl;
		list<struct node>::iterator itr=adj[i].begin();
		while(itr!=adj[i].end())
		{
			cout<<(*itr).x<<" "<<(*itr).gain<<" "<<(*itr).cost<<endl;
			itr++;
		}
		cout<<endl;
	}*/
	for(int i=1;i<=m;i++)
	{
			fin>>queries[i].u;
			fin>>queries[i].v;
			queries[i].id=i;
	}
	sort(queries.begin()+1,queries.end(),compare);
	/*for(int i=1;i<=m;i++)
        cout<<queries[i].u<<endl;*/
	for(int i=1;i<=m;i++)
    {
        int index=i;
        int parent=-1;
        mymap.reserve(m+1);
        mymap.insert({queries[i].v,queries[i].id});
        ctr=1;
        ctrcheck=0;
        while(i<=m && queries[i].u==queries[i+1].u)
        {
            mymap.insert({queries[i+1].v,queries[i+1].id});
            i++;
            ctr++;
        }
        dfs(queries[index].u,0,arr[queries[index].u],parent);
        mymap.clear();
    }
    for(int i=1;i<=m;i++)
    	cout<<ans[i]<<endl;
}
