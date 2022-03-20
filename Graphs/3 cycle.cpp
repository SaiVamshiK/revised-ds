

Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, 
then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which 
(P,Q), (Q,R) and (R,P) are connected by an edge.


#include <bits/stdc++.h>
using namespace std;

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
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j]==1)
            {
                for(int k=0;k<n;k++)
                {
                    if(edges[j][k]==1)
                    {
                        if(edges[k][i]==1)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<(cnt/6);
}



