

#include <bits/stdc++.h>
using namespace std;
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
    bool flag=false;
    queue<int> q;
    q.push(v1);
    visited[v1]=true;
    unordered_map<int,int> mp;
    while(!q.empty())
    {
		int elem=q.front();
        q.pop();
        if(elem==v2)
        {
            flag=true;
        	break;
        }
        for(int i=0;i<n;i++)
        {
            if((edges[elem][i]==1)&&(!visited[i]))
            {
                mp[i]=elem;
                visited[i]=true;
                q.push(i);
           }
        }
    }
    int end=v2;
    int src=mp[end];
    if(flag)
    {
        cout<<end<<' ';
		while(src!=v1)
        {
            cout<<src<<' ';
            src=mp[src];
        }
        cout<<v1;
    }
  	return 0;
}










