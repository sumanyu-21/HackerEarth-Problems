# include <iostream>
# include <bits/stdc++.h>
using namespace std;
vector<int>factors(100001);
int main()
{
	int n;
	cin>>n;
	fill(factors.begin(),factors.begin()+n+1,0);
	//unordered_map<int,int>mymap(100001);
	for(int i=1;i<=n;i++)
	{
		int height;
		cin>>height;
            for(int j=1;j<=sqrt(height);j++)
            {
                if(height%j==0)
                {
                    factors[j]++;
                    if(j!=sqrt(height))
                        factors[height/j]++;
                }
            }
	}
	//factors[1]=n;
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		cout<<factors[x]<<endl;
	}
}
