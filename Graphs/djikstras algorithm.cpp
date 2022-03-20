


#include<bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *dist,int n)
{
    int ans=-1;
    for(int i=0;i<n;i++)
    {
		if((!visited[i])&&((ans==-1)||(dist[ans]>dist[i])))
        {
            ans=i;
        }
    }
    return ans;
}
void findMinDist(int **edges,int n)
{
	bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int *dist=new int[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    for(int i=1;i<=(n-1);i++)
    {
        int minVertex=getMinVertex(visited,dist,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if((edges[minVertex][j]!=0)&&(!visited[j])&&(dist[minVertex]+edges[minVertex][j]<(dist[j])))
            {
                dist[j]=dist[minVertex]+edges[minVertex][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<' '<<dist[i]<<endl;
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
    findMinDist(edges,n);
  	return 0;
}

