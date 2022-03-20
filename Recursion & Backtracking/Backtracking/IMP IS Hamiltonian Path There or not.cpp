
A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. 
Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains two lines. The first line consists of two space separated integers N and M denoting 
the number of vertices and number of edges.Then in the next line are M space separated pairs u,v denoting an edge from u to v.

Output:
For each test case in a new line print 1 if a Hamiltonean path exists else print 0.

Constraints:
1<=T<=100
1<=N<=10
1<=M<=15

Example:
Input:
2
4 4
1 2 2 3 3 4 2 4
4 3
1 2 2 3 2 4
Output:
1
0

#include <bits/stdc++.h>
using namespace std;
bool func(int **edges,int sv,bool *visited,int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i])
        {
            cnt++;
        }
    }
    if(cnt==n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1&&(!visited[i]))
        {
            int adj=i;
            visited[adj]=true;
            bool ans=func(edges,adj,visited,n);
            if(ans)
            {
                return true;
            }
            visited[adj]=false;
        }
    }
    return false;
}
int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
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
        while(m--)
        {
            cin>>a>>b;
            a--;b--;
            edges[a][b]=1;
            edges[b][a]=1;
        }
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        bool done=false;
        for(int i=0;i<n;i++)
        {
            int sv=i;
            visited[sv]=true;
            bool ans=func(edges,sv,visited,n);
            if(ans)
            {
                done=true;
                break;
            }
            visited[sv]=false;
        }
        if(!done)
        {
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }
	return 0;
}
