



#include <bits/stdc++.h>
using namespace std;
void dfs(int **edges,int n,int sv,bool *visited)
{
	cout<<sv<<' ';
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if((edges[sv][i]==1)&&(!visited[i]))
        {
            dfs(edges,n,i,visited);
        }
    }
}
void bfs(int **edges,int n,int sv,bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while((!q.empty()))
    {
        int a=q.front();
        q.pop();
        cout<<a<<' ';
        for(int i=0;i<n;i++)
        {
            if((edges[a][i]==1)&&(!visited[i]))
            {
				q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
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
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(edges,n,i,visited);
        }
    }
  	return 0;
}









