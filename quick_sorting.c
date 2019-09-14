#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int p,int r)
{
	int i=p-1,j,temp;
	int pivot=a[r];
	for(j=p;j<r;j++)
	{
		if(a[j]<=pivot)
		{
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return (i+1);
}
void quick_sort(int a[],int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
int main()
{
	int i,n,a[50];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,1,n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}