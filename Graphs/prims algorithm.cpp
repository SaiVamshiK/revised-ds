



#include<bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *weight,int n)
{
	int ans=-1;
    for(int i=0;i<n;i++)
    {
        if((!visited[i])&&((ans==-1)||weight[ans]>weight[i]))
        {
            ans=i;
        }
    }
    return ans;
}
void prims(int **edges,int n)
{
	bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int *parent=new int[n];
    int *weight=new int[n];
    for(int i=0;i<n;i++)
    {
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=1;i<=(n-1);i++)
    {
        // get min vertex which is not visited and min weight
        int minVertex=getMinVertex(visited,weight,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if((edges[minVertex][j]!=0)&&(!visited[j]))
            {
                if((weight[j]>(edges[minVertex][j])))
                {
                    weight[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(i<parent[i])
        {
            cout<<i<<' '<<parent[i]<<' '<<weight[i]<<endl;
        }else{
            cout<<parent[i]<<' '<<i<<' '<<weight[i]<<endl;
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
    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        edges[a][b]=c;
        edges[b][a]=c;
    }
    prims(edges,n);
  	return 0;
}










