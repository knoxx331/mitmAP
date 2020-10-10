#include<bits/stdc++.h>
using namespace std;
void Sort(long long int wt[],long long int val[],long long int n)
{
	for(long long int i=0;i<n;i++)
	{
		for (long long int j=i;j<n;j++)
		{
			if(wt[i]>wt[j])
			{
				long long int t1,t2;
				t1=wt[i];
				wt[i]=wt[j];
				wt[j]=t1;
				t2=val[i];
				val[i]=val[j];
				val[j]=t2;
			}
		}
	}
}
int main()
{
	long long int n;
	cin>>n;
	long long int tot;
	cin>>tot;
	long long int val[n],wt[n];
	for (long long int i=0;i<n;i++)
	{
		cin>>wt[i]>>val[i];
	}
	Sort(wt,val,n);
	long long int T[n][tot+1];
	for (long long int i=0;i<n;i++)
	{
		T[i][0]=0;
	}
	for(long long int i=1;i<=tot;i++)
	{
			T[0][i]=val[0];	
	}
	for (long long int i=1;i<n;i++)
	{
		for (long long int j=1;j<=tot;j++)
		{
			if(j<wt[i])
			{
				T[i][j]=T[i-1][j];
			}
			else
			{
				T[i][j]=max(val[i]+T[i-1][j-wt[i]],T[i-1][j]);
			}
		}
	}
	cout<<T[n-1][tot]<<"\n";
}
