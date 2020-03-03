# include <iostream>
# include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define vec vector<int>
int main()
{
	int t;
	scanf("%intd",&t);
	vec ans(11);
	int k=0;
	while(t)
	{
		int var;
		int maxtime=-1;
		int  length;
		cin>>length;
		int upper[length];
		int bottom[length];
		for(int i=1;i<length;i++)
			scanf("%intd",&upper[i]);
		for(int i=1;i<length;i++)
			scanf("%d",&bottom[i]);
		for(int i=1;i<=length-1;i++)
		{
			var=i+max(bottom[i],upper[i]);
			maxtime=max(maxtime,var);
		}
		var=length;
		/*for(int i=1;i<=length;i++)
            cout<<time[i]<<"  ";*/
		maxtime=max(maxtime,var);
		ans[k]=maxtime;
		k++;
		t--;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;

}
