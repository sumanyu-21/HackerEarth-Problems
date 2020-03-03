# include <iostream>
# include <bits/stdc++.h>
# include <stdio.h>
# include <math.h>
using namespace std;
int algo(int arr[],int cumarr[], vector<int>primes,int dp[],int n)
{
    int maxscore=0,score;
    /*if(n==0)
    {
        dp[0]=0;
        return dp[0];
    }
    if(n<0)
        return 0;
    if(dp[n]==-1)
    {
        for(int i=n;i>=0;i--)
        {
            vector<int>::iterator itr=primes.begin();
            while(itr!=primes.end())
            {
                if(i-(*itr)+1<0)
                    break;
                else
                    score=algo(arr,cumarr,primes,dp,i-(*itr)-1);
                    if(i-*itr>=0)
                        score+=cumarr[i]-cumarr[i-(*itr)];
                    else
                        score+=cumarr[i];
                maxscore=max(maxscore,score);
                itr++;
            }
            dp[i]=maxscore;
        }
    }
    return dp[i];*/
    dp[0]=0;
    vector<int>::iterator itr=primes.begin();
    for(int i=1;i<=n;i++)
    {
        itr=primes.begin();
        while(itr!=primes.end())
        {
            if(i-(*itr)+1<0)
                break;
            else
            {
                score=(i-*itr-1)>0?dp[i-*itr-1]:0;
                if(i-*itr>=0)
                    score+=cumarr[i]-cumarr[i-(*itr)];
                else
                    score+=cumarr[i];
                maxscore=max(maxscore,score);
            }
            itr++;
        }
        dp[i]=maxscore;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int cumarr[n];
    cumarr[0]=arr[0];
    for(int i=1;i<n;i++)
        cumarr[i]=cumarr[i-1]+arr[i];
    int findprime[n+1];
    findprime[0]=0;
    findprime[1]=0;
    for(int i=2;i<=n;i++)
        findprime[i]=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(findprime[i]==1)
        {
            for(int j=i;i*j<=n;j++)
                findprime[i*j]=0;
        }
    }
    vector<int>primes;
    for(int i=0;i<=n;i++)
    {
        if(findprime[i]==1)
            primes.push_back(i);
    }
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=-1;
    int result=algo(arr,cumarr,primes,dp,n-1);
    int maxscore=0;
    for(int i=0;i<n;i++)
    {
        //cout<<dp[i]<<"  ";
        if(dp[i]>maxscore)
            maxscore=dp[i];
    }
    cout<<maxscore;
}

