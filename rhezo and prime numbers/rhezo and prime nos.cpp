# include <iostream>
# include <bits/stdc++.h>
# include <stdio.h>
# include <math.h>
using namespace std;
int main()
{
    int n;
	//cout<<"enter the value of n";
	scanf("%d",&n);
	int maxprime,flag=0;
	if(n>1)
    {
        for(int i=n;i>=0;i--)
        {
            flag=0;
            for(int j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==0)
            {
                maxprime=i;
                break;
            }

        }
    }
    else
        maxprime=0;
	//cout<<maxprime<<endl;
	int arr[n];
	for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
	int maxscore=0,previous=0;
	for(int i=0;i<maxprime;i++)
	{
		previous+=arr[i];
	}
	//cout<<previous;
	maxscore=previous;
	for(int i=1;i<=n-maxprime;i++)
	{
		previous=previous-arr[i-1]+arr[i+maxprime-1];
		maxscore=max(maxscore,previous);
	}
	cout<<maxscore;
}
