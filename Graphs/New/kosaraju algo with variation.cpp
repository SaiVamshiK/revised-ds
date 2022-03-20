

Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, 
which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.

Sol:
	in this problem if one domino is knocked then the domino to which it is associated to would be knocked off.
	we need to find out the min no. of such dominos to be knocked to completely knock off all the dominos.
	here it is a small variation of kosaraju algorithm
	in kosa algo funda is we find the transpose along with the stack so that the top element in the stack corresponds to one vertex in the isolated component of the transposed 
	graph, so that if we call dfs on the element on the top of the stack all the vertices of that particular isolated component would be obtained.
	i.e. a SCC would be obtained.
	but in a SCC we needed that every vertex has a path to all other vertices in the SCC.
	here the requirement is diff 
	we need to find the min. no of knocks to completely knock out the entire system.
	using SCC concept we can obtain the no. of moves to knock of the system but it is not min.
	in min. we need not have path from one vertex to all other vertices 
	even if one vertex has a path from all other vertices we may obtain min. no. of moves.
	so instead of having transpose of the graph we call dfs on the original graph itself so that the no. of vertices reached is maximized. thus minimizing no. of moves.

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

void dfs1(vector<int> *edges,bool *visited,int sv)
{
    visited[sv]=true;
    for(int i=0;i<(edges[sv].size());i++)
    {
        if(!visited[edges[sv][i]])
        {
            dfs1(edges,visited,edges[sv][i]);
        }
    }
}


int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m;
        vector<int> *edges=new vector<int>[n];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            a--;b--;
            edges[a].push_back(b);
        }
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
        int ans=0;
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
         	if(!visited[x])   
            {
                dfs1(edges,visited,x);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}







