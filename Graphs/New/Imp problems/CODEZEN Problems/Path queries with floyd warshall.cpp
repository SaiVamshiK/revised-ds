You are given a weighted graph with N vertices numbered from 1 to N and M edges, you have to answer Q queries. Every query is of the form U V. Print the minimum distance between nodes U and V, print -1 if there isn't any path.
Input Format :
Line 1 : Three space separated integers N M and Q.
Next M lines : Three space separated integers U V D denoting that there is an edge between node U and V with distance D
Next Q lines : Q queries. Each query contains two space separated integers U and V
Output Format :
For every query, print the required answer in different lines
***
Floyd warshall used
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,q;
    cin>>n>>m>>q;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=INT_MAX;
        }
    }
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        a--;b--;
        edges[a][b]=c;
        edges[b][a]=c;
    }
    for(int i=0;i<n;i++)
    {
        edges[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((edges[i][k]!=INT_MAX)&&(edges[k][j]!=INT_MAX)&&edges[i][j]>(edges[i][k]+edges[k][j]))
                {
                    edges[i][j]=edges[i][k]+edges[k][j];
                }
            }
        }
    }
    int u,v;
    while(q--)
    {
        cin>>u>>v;
        u--;v--;
        cout<<edges[u][v]<<endl;
    }
	return 0;
}

