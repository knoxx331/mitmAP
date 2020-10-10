#include<bits/stdc++.h>
using namespace std;
long long int merge(long long int arr[],long long int l,long long int m,long long int r)
{
	long long int ans=0;
	long long int i,j,k;
	long long int n1=m-l+1,n2=r-m;
	long long int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[m+j+1];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			ans+=n1-i;
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
	return ans;
}
void mergesort(long long int a[],long long int l,long long int r,long long int &count)
{
	long long int c=0;
	if(l<r)
	{
		long long int m=l+(r-l)/2;
		mergesort(a,l,m,count);
		mergesort(a,m+1,r,count);
		count+=merge(a,l,m,r);
	}
}
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int a[n];
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long int c=0;
		mergesort(a,0,n-1,c);
		cout<<c<<"\n";
	}
}
