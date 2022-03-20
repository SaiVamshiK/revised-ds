Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. 
A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.


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
    for(int i=0;i<e;i++)
    {
        edges[u[i]-1][v[i]-1]=1;
        edges[v[i]-1][u[i]-1]=1;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((edges[i][j]==1))
            {
                for(int k=0;k<n;k++)
                {
                    if((edges[j][k]==1)&&(edges[k][i]))
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    return (cnt/6);
}




