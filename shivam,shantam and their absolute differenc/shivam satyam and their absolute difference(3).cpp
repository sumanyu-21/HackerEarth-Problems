# include <iostream>
# include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
int algo(int **dp1,int a[],int n,int suma)
{
	for(int i=0;i<n;i++)
		dp1[i][0]=1;
	for(int j=1;j<=suma;j++)
	{
		if(j==a[0])
			dp1[0][j]=1;
		else
			dp1[0][j]=0;
	}
	int sum=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=suma;j++)
        {
            dp1[i][j]=j-a[i]>=0?(dp1[i-1][j-a[i]]%mod+dp1[i-1][j]%mod)%mod:dp1[i-1][j]%mod;
        }
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	int suma=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		suma+=a[i];
    }
	int sumb=0;
	for(int i=0;i<n;i++)
    {
        cin>>b[i];
        sumb+=b[i];

    }
    int q;
    cin>>q;
	int **dp1=new int*[n];
	for(int i=0;i<n;i++)
		dp1[i]=new int [suma+1];
	algo(dp1,a,n,suma);
	//cout<<"working"<<endl;
	int **dp2=new int*[n];
	for(int i=0;i<n;i++)
		dp2[i]=new int [sumb+1];
	algo(dp2,b,n,sumb);
	long long counter=0;
	//long long counter2=0;
	//cout<<"working"<<endl;
	for(int i=0;i<=suma;i++)
    {
        for(int j=0;j<=sumb;j++)
        {
            if(abs(i-j)>q && abs(i-j-1)<=q)
                break;
            else if(abs(i-j)<=q)
                counter=(counter+(dp1[n-1][i]*dp2[n-1][j])%mod)%mod;
        }
    }
    cout<<counter;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<=suma;j++)
			cout<<dp1[i][j]<<"  ";
		cout<<endl;
	}*/

}
