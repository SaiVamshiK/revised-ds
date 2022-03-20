
An island is a small piece of land surrounded by water . 
A group of islands is said to be connected if we can reach 
from any given island to any other island in the same group . 
Given V islands (numbered from 1 to V) and E connections or edges 
between islands. Can you count the number of connected groups of islands.

#include <bits/stdc++.h>
using namespace std;
void dfs(int **edges,int sv,bool *visited,int n)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1&&(!visited[i]))
        {
            dfs(edges,i,visited,n);
        }
    }
}
int main() {
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
        edges[a][b]=1;
        edges[b][a]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cnt++;
            dfs(edges,i,visited,n);
        }
    }
    cout<<cnt;
}

