#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N,X,check=0,score=0,i=0,sum;
	/*printf("enter the no of problems and difficulty level\n");*/
	scanf("%d%d",&N,&X);
	int A[N];
	for(i;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	i=0;
	for(i;i<N;i++)
	{
		if(check<=1 && A[i]<=X)
			++score;
		else if(A[i]>X)
		{
			check++;
			if(check==2)
            {
				break;
            }
		}

	}
	printf("%d",score);
	return 0;
}
