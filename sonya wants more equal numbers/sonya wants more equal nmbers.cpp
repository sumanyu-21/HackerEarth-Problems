# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int dp[100][100];
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		dp[i][i]=arr[i];
	}
	int counter=0;
	list<int>mylist;
	for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            dp[i][j]=dp[i][j-1]+arr[j];
    }
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{

			for(int k=i;k<=j-1;k++)
			{
				if(dp[i][k]==dp[k+1][j])
				{
					counter++;
					mylist.push_back(dp[i][k]);
				}
			}
		}
	}
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<"  ";
        cout<<endl;
    }
	cout<<counter<<endl;
	list<int>::iterator itr=mylist.begin();
	while(itr!=mylist.end())
	{
		cout<<*itr<<" ";
		itr++;
	}
}
