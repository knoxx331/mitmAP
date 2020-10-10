#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,pat;
	cout<<"ENTER STRING AND PATTERN\n";
	cin>>s>>pat;
	vector <vector<bool> > T(s.length()+1,vector<bool> (pat.length()+1,false));
	T[0][0]=true;
	for (int i=1;i<=pat.length();i++)
	{
		if((pat[i-1]=='*' || pat[i-1]=='.') && i>1)
		{
			T[0][i]=T[0][i-2];
		}
		else if(pat[i-1]=='*' || pat[i-1]=='.')
		{
			T[0][i]=true;
		}
	}
	for (int i=1;i<=s.length();i++)
	{
		for (int j=1;j<=pat.length();j++)
		{
			if(s[i-1]==pat[j-1] || pat[j-1]=='.')
			{
				T[i][j]=T[i-1][j-1];
			}
			else if(pat[j-1]=='*')
			{
				T[i][j]=T[i][j-2];
				if(!T[i][j])
				{
					if(s[i-1]==pat[j-2] || pat[j-2]=='.')
					{
						T[i][j]=T[i-1][j];
					}
				}
			}
		}
	}
	for (int i=0;i<=s.length();i++)
	{
		for (int j=0;j<=pat.length();j++)
		{
			cout<<T[i][j]<<" ";
		}cout<<"\n";
	}
}
