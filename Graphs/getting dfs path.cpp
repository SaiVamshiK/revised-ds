
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.

#include <bits/stdc++.h>
using namespace std;
void dfs(int **edges,int n,bool *visited,vector<int> &ans,int sv,int ev,bool &flag)
{
    visited[sv]=true;
    if(sv==ev)
    {
        flag=true;
        return;
    }
    for(int i=0;i<n;i++)
    {
		if((edges[sv][i]==1)&&(!visited[i]))
        {
            dfs(edges,n,visited,ans,i,ev,flag);
            if(flag)
            {
                ans.push_back(i);
                return ;
            }
        }
    }
}

int main()
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
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    vector<int> ans;
    bool flag=false;
    dfs(edges,n,visited,ans,v1,v2,flag);
    if(flag)
    {
        ans.push_back(v1);
    }
    for(int i=0;i<(ans.size());i++)
    {
        cout<<ans[i]<<' ';
    }
  	return 0;
}













