

Given an undirected graph G(V,E), check if the graph G is connected graph or not.


#include <bits/stdc++.h>
using namespace std;
void bfs(int **edges,int sv,bool *visited,int n)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(edges[temp][i]==1&&(!visited[i]))
            {
                q.push(i);
                visited[i]=true;
            }
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
    bfs(edges,0,visited,n);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
}


