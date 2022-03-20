


Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 .
We define node 's' to be the starting position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to 
all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes 
(ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2

Sample Output

6 6 -1
-1 6



#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,e;
		cin>>n>>e;
		int **edges=new int*[n];
		for(int i=0;i<n;i++)
		{
			edges[i]=new int[n];
			for(int j=0;j<n;j++)
			{
				edges[i][j]=0;
			}
		}
		int a,b;
		for(int i=0;i<e;i++)
		{
			cin>>a>>b;
			a--;b--;
			edges[a][b]=1;
			edges[b][a]=1;
		}
		int s;
		cin>>s;
		s--;
		int *dist=new int[n];
		for(int i=0;i<n;i++)
		{
			dist[i]=0;
		}
		bool *visited=new bool[n];
		for(int i=0;i<n;i++)
		{
			visited[i]=false;
		}
		queue<int> q;
		q.push(s);
		visited[s]=true;
		unordered_map<int,int> mp;
		mp[s]=-1;
		while(!q.empty())
		{
			int cur=q.front();
			q.pop();
			if(mp[cur]!=-1)
			{
				dist[cur]=dist[cur]+6+dist[mp[cur]];
			}
			for(int i=0;i<n;i++)
			{
				if(edges[cur][i]!=0&&(!visited[i]))
				{
					q.push(i);
					visited[i]=true;
					mp[i]=cur;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(dist[i]==0)
			{
				dist[i]=-1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i!=s)
			{
				cout<<dist[i]<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}


