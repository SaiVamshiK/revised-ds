



#include <bits/stdc++.h>
using namespace std;

void print(int **edges,int sv,bool *visited,int n)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<' ';
        for(int i=0;i<n;i++)
        {
            if(i==sv)
            {
                continue;
            }
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
    for(int i=0;i<n;i++)
    {
		if(!visited[i])
        {
			print(edges,i,visited,n);
        }
    }
}









