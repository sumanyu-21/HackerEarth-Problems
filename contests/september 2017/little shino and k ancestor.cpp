# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int table[1000001][23];
bool mark[1000001];
//int outdegree[1000001];
int colour[1000001];
int arr[1000001];
vector<list<int> >adj(1000001);

int logc(int x) {
    return 32 - __builtin_clz(x) - 1;
}
int dfs(int s)
{
	mark[s]=true;
	int temp1;
	table[s][0]=colour[arr[s]];
	//if(outdegree[s]>1)
    //{
        temp1=colour[arr[s]];
        colour[arr[s]]=s;
        //temp=s;
    //}
    /*else
    {
        temp=colour[arr[s]];
        colour[arr[s]]=s;
    }*/
	for(auto p:adj[s])
	{
        //table[p][0]=colour[arr[p]];
        //int temp=colour[arr[p]];
        //colour[arr[p]]=p;
        if(!mark[p])
        {
            dfs(p);
            //colour[arr[s]]=s;
        }
    }
    //if(outdegree[s]>1)
    colour[arr[s]]=temp1;
}
int main()
{
    //ifstream fin("little shino.txt");
	int n,k;
	cin>>n>>k;
	//cout<<log(1000000);
	int MAXLOGN=logc(n)+1;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	/*for(int i=1;i<=1000000;i++)
        colour[i]=-1;*/
	//fill(outdegree,outdegree+n+1,0);
	//fill(mark,mark+n+1,false);
	//colour[arr[1]]=1;
	/*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=MAXLOGN;j++)
            table[i][j]=0;
    }*/
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		//outdegree[a]++;
		//adj[b].push_back(a);
	}
    if(n>1)
    {
    	dfs(1);
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
                if(mid!=0)
                    table[i][j]=table[mid][j-1];
            }
        }
        /*for(int i=1;i<=n;i++)
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
            for(int d=0;d<=MAXLOGN && u !=0;d++)
            {
                if(((1<<d)&K)>0)
                {
                    u=table[u][d];
                }
            }
            if(u!=0)
                cout<<u<<" ";
            else
                cout<<"-1 ";
            /*if(flag==0)
                cout<<u<<" ";
            else
                cout<<"-1 ";*/
            /*int i=0;
            while(K>0)
            {
                if(K&1)
                    u=table[u][i];
                i+=1;
                K=K>>1;
                if(u==-1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                cout<<"-1 ";
            else
                cout<<u<<" ";*/
        }
    }
    else
        cout<<"-1 ";

}
