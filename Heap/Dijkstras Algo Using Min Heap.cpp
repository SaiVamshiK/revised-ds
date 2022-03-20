
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using 
Dijkstra's Algorithm.

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
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
    int a,b,c;
    while(e--)
    {
        cin>>a>>b>>c;
        edges[a][b]=c;
        edges[b][a]=c;
    }
    int *dist=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dist[i]=INT_MAX;
    }
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    dist[0]=0;
    pq.push({0,0});
    for(int i=0;i<(n-1);i++)
    {
        while(visited[pq.top().second])
        {
            pq.pop();
        }
        int minVertex=pq.top().second;
        pq.pop();
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0&&(!visited[j]))
            {
                if(dist[j]>(edges[minVertex][j]+dist[minVertex]))
                {
                    dist[j]=edges[minVertex][j]+dist[minVertex];
                    pq.push({dist[j],j});
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<' '<<dist[i]<<endl;
    }
}


























