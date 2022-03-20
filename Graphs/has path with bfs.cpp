



#include <bits/stdc++.h>
using namespace std;
bool has(int **edges,int n,bool *visited,int sv,int ev)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int elem=q.front();
        q.pop();
        if(elem==ev)
        {
            return true;
        }
        for(int i=0;i<n;i++)
        {
            if((edges[elem][i]==1)&&(!visited[i]))
            {
                visited[i]=true;
                q.push(i);
            }
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
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    if(has(edges,n,visited,v1,v2))
    {
        cout<<"true";
    }else{
        cout<<"false";
    }
  	return 0;
}





