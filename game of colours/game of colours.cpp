# include <iostream>
# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	//int dp[100][100][100][100][3];
	int *****dp=new int ****[n];
	for(int i=0;i<n;i++)
    {
        dp[i]=new int ***[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j]=new int **[n];
            for(int k=0;k<n;k++)
            {
                dp[i][j][k]=new int *[n];
                for(int l=0;l<3;l++)
                    dp[i][j][k][l]=new int[3];
            }
        }
    }
    int t[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>t[i][j];
    }
}
