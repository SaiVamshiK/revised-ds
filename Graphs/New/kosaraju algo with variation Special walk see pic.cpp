#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,bool *visited,stack<int> &s,int sv)
{
	visited[sv]=true;
    for(int i=0;i<(edges[sv].size());i++)
    {
        if(!visited[edges[sv][i]])
        {
            dfs(edges,visited,s,edges[sv][i]);
        }
    }
    s.push(sv);
}
void dfs1(vector<int> *edges,bool *visited,int sv,vector<int> &cur)
{
    visited[sv]=true;
    cur.push_back(sv);
    for(int i=0;i<(edges[sv].size());i++)
    {
        if(!visited[edges[sv][i]])
        {
            dfs1(edges,visited,edges[sv][i],cur);
        }
    }
}
int main() {
	int n,m;
    int a,b;
    cin>>n>>m;
    vector<int> *edges=new vector<int>[n];
    vector<int> *t_edges=new vector<int>[n];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--;b--;
        edges[a].push_back(b);
        t_edges[b].push_back(a);
    }
    vector<int> ret(n,0);
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(edges,visited,s,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
     	if(!visited[x])   
        {
        	vector<int> cur;
            dfs1(t_edges,visited,x,cur);
            if(cur.size()>1)
            {
            	for(int i=0;i<(cur.size());i++)
            	{
            		ret[cur[i]]=1;
				}
			}
        }
    }
    for(int i=0;i<n;i++)
    {
    	cout<<ret[i]<<' ';
	}
}

