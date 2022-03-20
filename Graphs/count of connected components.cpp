
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
int solve(int n,int e,vector<int>u,vector<int>v)
{
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
    for(int i=0;i<e;i++)
    {
        edges[u[i]-1][v[i]-1]=1;
        edges[v[i]-1][u[i]-1]=1;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
		if(!visited[i])
        {
            cnt++;
            dfs(edges,n,i,visited);
        }
    }
    return cnt;
}










