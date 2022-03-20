#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int i,int j,int n,int m,bool **visited,int &size)
{
	visited[i][j]=true;
	size++;
	if((i+1<n)&&(edges[i+1][j]==1)&&(!visited[i+1][j]))
	{
		dfs(edges,i+1,j,n,m,visited,size);
	}
	if((j+1<m)&&(edges[i][j+1]==1)&&(!visited[i][j+1]))
	{
		dfs(edges,i,j+1,n,m,visited,size);
	}
	if((i-1>=0)&&(edges[i-1][j]==1)&&(!visited[i-1][j]))
	{
		dfs(edges,i-1,j,n,m,visited,size);
	}
	if((j-1>=0)&&(edges[i][j-1]==1)&&(!visited[i][j-1]))
	{
		dfs(edges,i,j-1,n,m,visited,size);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int **edges=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>edges[i][j];
		}
	}
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
		{
			visited[i][j]=false;
		}
	}
	int ans=INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(edges[i][j]==0)
			{
				int size=0;
				dfs(edges,i,j,n,m,visited,size);
				ans=max(ans,size);
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
					{
						visited[i][j]=false;
					}
				}
			}
		}
	}
	cout<<"Size:"<<ans<<endl;
}


