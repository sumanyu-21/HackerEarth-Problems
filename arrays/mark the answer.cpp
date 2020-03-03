#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

/*template <typename T, size_t N> const T* mybegin(const T (&a)[N]) { return a; }
template <typename T, size_t N> const T* myend  (const T (&a)[N]) { return a+N; }*/

int i=0;
int fun(int *A,int X)
{
	int sum=0;
	i++;
	while(A[i]<=X)
	{
		sum++;
		i++;

	}
	return sum;
}

int main()
{
	int N,X,check=0,k=0,r=1,sum,max_score,score=0;
	/*printf("enter the no of problems and difficulty level\n");*/
	scanf("%d%d",&N,&X);
	int A[N];
	int B[N+1];
	for(i=0;i<=N;i++)
        B[i]=0;
	B[N]=999999;
	/*printf("enter the problem difficulties\n");*/
	i=0;
	for(i;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	i=0;
	for(i;i<N;i++)
	{
		if(A[i]<=X)
			{
			    /*score++;
			    B[k]=score;*/
			    B[k]++;
			}
		else if(A[i]>X && A[i+1]<=X)
		{
			sum=fun(A,X);
			B[k]=B[k]+sum;
			k++;
			B[k]=sum;
			i--;
			/*score=0;*/
		}
		else
		{
		    /*B[k]=score;
		    score=0;
			k++;*/
			k++;


			/*check++
			if(A[i+1]<N)
			{
				B[r]++;
				r++;
			}

			if(check>1)
			{
				k++;
				marks=0;
			}*/
		}
	}
	max_score=B[0];
	/*for(i=0;i<k;i++)
    {
        printf("%d  ",B[i]);
    }
    printf("\n");*/
	for(i=1;i<k;i++)
    {
        if(B[i]>max_score)
            max_score=B[i];
    }
   /* printf("maximum score is % d",max_score);*/
    printf("%d",max_score);
    return 0;
}

