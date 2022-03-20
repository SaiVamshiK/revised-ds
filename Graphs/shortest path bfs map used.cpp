


Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.


#include <bits/stdc++.h>
using namespace std;

void print(int **edges,int sv,int ev,bool *visited,int n)
{
    queue<int > q;
    q.push(sv);
    visited[sv]=true;
    unordered_map<int,int> mp;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        if(temp==ev)
        {
            cout<<ev<<' ';
            int x=ev;
            while(x!=sv)
            {
                cout<<mp[x]<<' ';
                x=mp[x];
            }
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(edges[temp][i]&&(!visited[i]))
            {
                q.push(i);
                mp[i]=temp;
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
    cin>>a>>b;
    print(edges,a,b,visited,n);
}






