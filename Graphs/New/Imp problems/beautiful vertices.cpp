
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.

Input Format
First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.

Constraints
1 <= N <= 100000 0 <= M <= N-1 1 <= x,y <= N

Output Format
Print the number of beautiful vertices in the graph.

Sample Input
4 3
1 2
2 3
2 4
Sample Output
1
Explanation
In this graph, we have vertices 1,2,3 and 4. Since 1 is the lowest among these, so it becomes the master vertex. Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex. There are no more beautiful vertices in the graph.

#include<bits/stdc++.h>
using namespace std;
int dfs(vector<int> *edges,int sv,bool *visited,int parent,int &ans)
{
	visited[sv]=true;
	int cnt=0;
	vector<int> vec;
	for(int i=0;i<(edges[sv].size());i++)
	{
		int adj=edges[sv][i];
		if(!visited[adj])
		{
			int temp=dfs(edges,adj,visited,sv,ans);
			vec.push_back(temp);
			cnt++;
		}
	}
	for(int i=0;i<(vec.size());i++)
	{
		if(vec[i]>cnt)
		{
			ans++;
		}
	}
	return cnt;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> *edges=new vector<int>[n];
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(edges,i,visited,i,ans);
		}
	}
	cout<<ans;
}
