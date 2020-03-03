#include<bits/stdc++.h>
 
using namespace std;
 
int const lim = 1e6+3;
int const MLOG = 22;    //  Log(n)
 
int table[lim][MLOG];   // to store for node i the 2^jth parent 
 
vector<int> adj[lim];   // to store for each node all its neighbors
 
int N, K, U;
 
void DFS(int u, int p = -1)
{
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(v != p)
		{
			table[v][0] = u;
			DFS(v, u);
		}
	}
}
 
void build ()
{
	for( int j = 1; j < MLOG ; j++)
	{
		for(int i = 1; i <= N ;i++)
		{
			table[i][j] = table[table[i][j-1]][j-1];
		}
	} 
}
 
int kth(int u,int k)
{
	for(int i = MLOG ;i>=0;i--)
	{
		if((1<<i) <= k )
		{
			u = table[u][i];
			k-=(1<<i);
		}
	}return u;
 
}
 
int main()
{
	cin >> N >> U >>  K;
	for(int i = 0;i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DFS(1);
	build();
	cout << kth(U,K) << endl;
}