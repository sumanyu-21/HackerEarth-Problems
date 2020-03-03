//micro and array update;
#include <bits/stdc++.h>
using namespace std;
int second=0,T,r=0;
/*int fun2(int index,int *t)
{
	for(int i=0;i<=index;i++)
	{
		A[i]=A[i]+1;
	}
	second++;
	return 0;
}*/
int fun3(int N,int K,int *t)
{
	int index=-1,diff;
	int A[N];
	/*printf("enter the array elements\n");*/
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	diff=K-A[0];
	if(diff<0)
		second=0;
	else
		second=diff;
	t[r]=second;
	r++;
	second=0;
}


int fun(int N,int K,int *t)
{
	int index=-1,diff;
	int A[N];
	/*printf("enter the array elements\n");*/
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	/*for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}*/
	/*printf("\n");*/
			for(int i=0;i<N;i++)
			{
				if(A[i]<K)
					index=i;
				else if(A[i]==K)
				{
					index=i-1;
					break;
				}
				else
					break;
			}
		/*	diff=K-A[index];
			for(int i=0;i<=index;i++)
			{
				A[i]=A[i]+diff;
			}
			second=second+diff;*/

			/*printf("%d\n",index);*/
			/*fun2(index,t);*/
		while(A[0]<K)
		{
			diff=K-A[index];
			for(int i=0;i<=index;i++)
				A[i]=A[i]+diff;
			second=second+diff;

			/*loop:   if(A[index]>A[index-1])
						index--;
					else if(A[index]==A[index-1])
					{
						index--;
						goto loop;
					}*/
			while(A[index]==A[index-1])
			{
				index--;
			}
			index--;

		}
		t[r]=second;
		r++;
		second=0;

	return 0;
}
int main()
{
	/*printf("hello\n");
	return 0;*/
	int N,K,i;/**t=new int[N];*/
	/*printf("enter the no of test cases\n");*/
	scanf("%d",&T);
	int t[T];
	while(T)
	{
		/*printf("enter the no of elements and valueof K\n");*/
		scanf("%d%d",&N,&K);
		fun3(N,K,t);
		T--;
	}
	/*printf("total seconds taken are \n");*/
	for(i=0;i<r;i++)
	{
		printf("%d \n",t[i]);
	}
	return 0;
}
