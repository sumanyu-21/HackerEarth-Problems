#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,i;
	int *A=(int *)malloc(N*sizeof(int));
	int *B=(int *)malloc(N*sizeof(int));
	int *C=(int *)malloc(N*sizeof(int));
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&A[i-1]);
	}
	for(i=1;i<=N;i++)
	{
		scanf("%d",&B[i-1]);
	}
	for(i=1;i<=N;i++)
	{
		C[i-1]=A[i-1]+B[i-1];
		printf("%d ",C[i-1]);
	}
	return 0;
}
