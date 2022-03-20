



#include <bits/stdc++.h>
using namespace std;
void dfs(int **edges,int n,int sv,bool *visited)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if((edges[sv][i]==1)&&(!visited[i]))
        {
            dfs(edges,n,i,visited);
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
    dfs(edges,n,v1,visited);
    if(!visited[v2])
    {
        cout<<"false";
    }else{
        cout<<"true";
    }
  	return 0;
}





