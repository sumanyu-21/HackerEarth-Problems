# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int table[1000001][25];
bool mark[1000001];
//int outdegree[1000001];
//int colour[1000001];
int arr[1000001];
vector<list<int> >adj(1000001);

int logc(int x) {
    return 32 - __builtin_clz(x) - 1;
}
int dfs(int s)
{
    mark[s]=true;
	for(auto p:adj[s])
	{
        if(!mark[p])
        {
            table[p][0]=s;
            dfs(p);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin("little shino.txt");
	int n,k;
	cin>>n>>k;
	int MAXLOGN=logc(n)+1;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	fill(mark,mark+n+1,false);
	for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=MAXLOGN;j++)
            table[i][j]=-1;
    }
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	//cout<<"working"<<endl;
	/*for(int i=1;i<=n;i++)
	{
		cout<<i<<" : "<<table[i][0]<<endl;
	}*/
    for(int j=1;j<=MAXLOGN;j++)
    {
        for(int i=1;i<=n;i++)
        {
            //if(table[i][j-1]==-1)
              //  table[i][j]=-1;
            //else
            int mid=table[i][j-1];
            if(mid!=-1)
                table[i][j]=table[mid][j-1];
        }
    }
   /* for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=MAXLOGN;j++)
            cout<<table[i][j]<<"  ";
        cout<<endl;
    }*/
    for(int j=1;j<=n;j++)
    {
        int u=j;
        int K=k;
        //int flag=0;
        for(int d=0;d<=MAXLOGN && u !=-1;d++)
        {
            if(((1<<d)&K)>0)
            {
                u=table[u][d];
            }
        }
        if(u!=-1 && arr[u]==arr[j])
            cout<<u<<" ";
        else
            cout<<"-1 ";

    }

}
