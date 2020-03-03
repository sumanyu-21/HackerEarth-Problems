#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,Bi,i,Q,flag,k=0;
	/*cout<<"enter the value of N\n";*/
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
    sort(a, a+N);
   /* for(int i=0;i<N;i++)
    {
    	cout<<a[i]<<" ";
    }*/
   /* cout<<"enter the no of queries\n";*/
    scanf("%d",&Q);
    int b[Q];
   /* while(Q)
    {
        flag=0;
    	/*cout<<"enter the number to be counted in array\n";
    	scanf("%d",&Bi);
        if(Bi>a[N-1]||Bi<a[0])
        {
            b[k]=flag;
            k++;
        }
    	else
        {
            for(i=0;i<N;i++)
    	    {
    		    if(a[i]>Bi)
    			    break;
    		    else if(a[i]==Bi)
    			    flag++;
    	    }
            b[k]=flag;
    	    k++;
        }
        Q--;
    }*/
    for(i=0;i<Q;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<Q;i++)
    {
        flag=0;
        if(b[i]>a[N-1]||b[i]<a[0])
            b[i]=flag;
    	else
        {
            for(int j=0;j<N;j++)
    	    {
    		    if(a[j]==b[i])
    			    flag++;
    		    else if(a[j]>b[i])
    			    break;
    	    }
            b[i]=flag;
        }

    }
    for(i=0;i<Q;i++)
    {
    	if(b[i]==0)
    		printf("NOT PRESENT\n");
    	else
    		printf("%d\n",b[i]);
    }
	return 0;
}
