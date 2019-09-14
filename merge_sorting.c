#include<stdio.h>
void merge(int a[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];
	int i,j;
	for(i=1;i<=n1;i++)
	{
		L[i]=a[p+i-1];
	}
	for(i=1;i<=n2;i++)
	{
		R[i]=a[q+i];
	}
	L[n1+1]=999;
	R[n2+1]=999;
	i=1,j=1;
	while(p<=r)
	{
		if(L[i]<=R[j])
		{
			a[p]=L[i];
			i++;
		}
		else
		{
			a[p]=R[j];
			j++;
		}
		p++;
	}
}
void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}	
}
int main()
{
	int i,j,n,a[50];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,1,n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}