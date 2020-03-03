# include <iostream>
# include <bits/stdc++.h>
using namespace std;
struct house
{
	int prof;
	int index;
};
bool compare(struct house x,struct house y)
{
	return x.prof>y.prof;
}
vector<struct house>profit(501);
int main()
{
	int n,k,m;
	cin>>n>>k>>m;
	int buildcost[n+1];
	int willing[m+1][n+1];
	for(int i=1;i<=n;i++)
	{
		profit[i].prof=0;
		profit[i].index=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>willing[i][j];
			profit[j].prof+=willing[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>buildcost[i];
		profit[i].prof-=buildcost[i];
	}
	sort(profit.begin()+1,profit.begin()+n+1,compare);
	for(int i=1;i<=k;i++)
		cout<<profit[i].index<<" ";
}
