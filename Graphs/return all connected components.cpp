#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int n,int sv,bool *visited,vector<int> &ans)
{
    visited[sv]=true;
    ans.push_back(sv);
    for(int i=0;i<n;i++)
    {
        if((edges[sv][i]==1)&&(!visited[i]))
        {
            dfs(edges,n,i,visited,ans);
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
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> ans;
            dfs(edges,n,i,visited,ans);
            sort(ans.begin(),ans.end());
            for(int j=0;j<(ans.size());j++)
            {
                cout<<ans[j]<<' ';
            }
            cout<<endl;
        }
    }
	return 0;
}











