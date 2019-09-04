#include <stdio.h>

int maximum(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main() 
{
	int w[10],v[10],k[50][50],profit,weight,weight1;
	int i,n,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&w[i]);
	}
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&v[i]);
	}
	scanf("%d",&weight);
	for(i=0;i<n;i++)
	{
	    for(j=0;j<weight;j++)
	    {
	        k[i][j]=0;
	    }
	}
	weight1=weight;
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=weight;j++)
	    {
	        if(w[i]>j)
	        {
	            k[i][j]=k[i-1][j];
	        }
	        else
	        {
	            k[i][j]=maximum(v[i]+k[i-1][j-w[i]],k[i-1][j]);
	        }
	    }
	}
	printf("Profit::%d\n",k[n][weight]);
	printf("----------------\n");
	for(i=0;i<=n;i++)
	{
	    for(j=0;j<=weight;j++)
	    {
	        printf("%d ",k[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}
