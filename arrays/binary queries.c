#include<stdio.h>
#include<stdlib.h>
int N;
void fun1X(int *p)
{
    int pos,i;
   /* printf("enter the position to be flipped");*/
	/*printf("1 ");*/
	scanf("%d",&pos);
	*(p+pos-1)=(*(p+pos-1)+1)%2;
	/*for(i=1;i<=N;i++)
    {
        printf("%d ",p[i-1]);
    }*/
}
void fun0LR(int *p)
{
	int L,R,sum=0,i;
	/*printf("enter the value of l and r\n");*/
	/*printf("0 ");*/
	scanf("%d%d",&L,&R);
	/*for(i=R-1;i>=L-1;i--)
	{
		sum=sum+p[i]*(2^(N-R));
	}
	if(sum%2==0)
		printf("even\n");
	else
		printf("odd\n");
	}*/
	if(*(p+R-1)==1)
		printf("ODD\n");
	else
		printf("EVEN\n");
}
int main()
{
	int Q,i,b,q,x,y;
	/*printf("enter the number of bits and no of queries to be performed\n");*/
	scanf("%d%d",&N,&Q);
	int *p=(int*)malloc(N*sizeof(int));
	/*printf("enter the bits\n");*/
	for(i=1;i<=N;i++)
	{
		scanf("%d",&b);
		p[i-1]=b;
	}

	/*for(i=1;i<=N;i++)
    {
        printf("%d ",p[i-1]);
    }*/
	while(Q)
	{
	/*	if(Q>0)
		{
			fun1X(p);
			Q--;
		}
		if(Q>0)
		{
			fun0LR(p);
		    Q--;
		}*/
        scanf("%d",&q);
        if(q==1)
        {
        	fun1X(p);
        	Q--;
        }
        else
        {
			fun0LR(p);
			Q--;
		}
	}
	return 0;
}
