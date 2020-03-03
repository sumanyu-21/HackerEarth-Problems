
# include <iostream>
# include <bits/stdc++.h>
# define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef unsigned long long int ll;
typedef vector<vector<ll> >matrix;
const ll MOD=1000000007;
const ll K=2;

matrix mul(matrix A,matrix B)
{
	matrix C(K,vector<ll>(K,0));
	REP(i,K)  REP(j,K) REP(k,K)
	C[i][j]=(C[i][j]+A[i][k]*B[k][j]%MOD)%MOD;
	return C;
}
matrix pow(matrix A,ll p)
{
	matrix result(K,vector<ll>(K));
	result[0][0]=1, result[0][1]=1;
	result[1][0]=1, result[1][1]=0;

	while(p>0)
	{
		if(p&1)
			result=mul(result,A);
		A=mul(A,A);
		p=p>>1;
	}
	return result;
}
int fib(ll N,matrix F1,matrix T)
{

	if(N==0)
		return 2;
    if(N==1)
        return 3;
	T=pow(T,N-2);
	ll res=0;
	REP(i,K)
		res=(res+(T[0][i]*F1[i][0])%MOD)%MOD;
		return res;
}
int main()
{
    ll t;
    cin>>t;
    matrix F1(K,vector<ll>(1));
	//vector<ll> F1(k+1);
	F1[0][0]=3;
	F1[1][0]=2;

	matrix T(K,vector<ll>(K));
	T[0][0]=1, T[0][1]=1;
	T[1][0]=1, T[1][1]=0;
    vector<ll>ans(60001);
    ll k=0;
    while(t)
    {   ll n;
        cin>>n;
        ll result=fib(n-1,F1,T);
        //cout<<result<<endl;
        t--;
        ans[k]=result;
        k++;
    }
    for(ll i=0;i<k;i++)
        cout<<ans[i]<<endl;
}

