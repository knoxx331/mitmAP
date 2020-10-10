#include<bits/stdc++.h>
using namespace std;
long long int s1(vector<long long int> adj[],long long int n,long long int s)
{
	vector<bool> vis(n+1,false);
	vis[s]=true;
	queue<long long int> q;
	q.push(s);
	long long int lev[n+1];
	lev[s]=0;
	long long int levv=0;
	while(!q.empty())
	{
		long long int h=q.front();
		q.pop();
		for(long long int i=0;i<adj[h].size();i++)
		{
			if(!vis[adj[h][i]])
			{
				vis[adj[h][i]]=true;
				lev[adj[h][i]]=lev[h]+1;
				if(levv<lev[adj[h][i]])
				{
					levv=lev[adj[h][i]];
				}
				q.push(adj[h][i]);
			}
		}
	}
	return levv;
}
long long int search(vector<long long int> adj[],long long int n)
{
	vector<bool> vis(n+1,false);
	vis[1]=true;
	queue<long long int> q;
	q.push(1);
	long long int lev[n+1];
	lev[1]=0;
	long long int x=1,levv=0;
	while(!q.empty())
	{
		long long int h=q.front();
		q.pop();
		for(long long int i=0;i<adj[h].size();i++)
		{
			if(!vis[adj[h][i]])
			{
				vis[adj[h][i]]=true;
				lev[adj[h][i]]=lev[h]+1;
				if(levv<lev[adj[h][i]])
				{
					levv=lev[adj[h][i]];
					x=adj[h][i];
				}
				q.push(adj[h][i]);
			}
		}
	}
	return s1(adj,n,x);
}
int main()
{
	long long int n;
	cin>>n;
	vector<long long int> adj[n+1];
	for(long long int i=1;i<n;i++)
	{
		long long int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<search(adj,n);
}
