# include <iostream>
# include <bits/stdc++.h>
# include <math.h>
using namespace std;
typedef unsigned long long ll;
ll sumofdigits(ll n)
{
	ll sum=0;
	while(n>0)
	{
		sum+=n%10;
		n=n/10;
	}
	return sum;
}
ll algo(ll n,ll checkarr[])
{
	ll result;
	if(n==1 || n==4)
		return 1;
	/*unordered_map<int,int>mymap;
	mymap.reserve(1000000);*/
	while(n!=4 || n!=1)
	{
	    //mymap.insert(n,n);
		n=sumofdigits(n*n);
		//cout<<n<<endl;
		if(n==4 ||n==1)
        {
            result=1;
            break;
        }
		//if(mymap.find(n)!=mymap.end())
		if(checkarr[n]==1)
        {
            result=-1;
            break;
        }
		//mymap.insert(std::make_pair((int)n,(int)n));
		checkarr[n]=1;
	}
	return result;
}
int main()
{
	ll t;
	scanf("%" SCNu64 , &t);
	//cin>>t;
    vector<ll>ans(1000005);
	ll k=0;
	while(t--)
	{
		ll n;
		ll checkarr[163];
        for(int i=0;i<163;i++)
        checkarr[i]=-1;
		//cin>>n;
		scanf("%" SCNu64 , &n);
		ll result=algo(n,checkarr);
		ans[k]=result;
		k++;
	}
	for(ll i=0;i<k;i++)
	{
		if(ans[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
