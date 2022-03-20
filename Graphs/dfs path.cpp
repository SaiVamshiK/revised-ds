

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.


#include <bits/stdc++.h>
using namespace std;

bool print(int **edges,int sv,int ev,bool *visited,int n)
{
    visited[sv]=true;
    if(sv==ev)
    {
        cout<<sv<<' ';
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue ;
        }
        if(edges[sv][i]==1&&(!visited[i]))
        {
            bool temp=print(edges,i,ev,visited,n);
            if(!temp)
            {
                return false;
            }
            cout<<(sv)<<' ';
            return true;
        }
    }
    return false;
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
    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
	int v1,v2;
    cin>>v1>>v2;
    print(edges,v1,v2,visited,n);
}





