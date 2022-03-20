****************************	SEE THIS APPROACH (cycle detection digraph)	SOMETIMES TLE	****************************
void dfs(vector<int> *edges,int sv,bool *visited,bool &ans)
{
    visited[sv]=true;
    for(int i=0;i<(edges[sv].size());i++)
    {
        int adj=edges[sv][i];
        if(visited[adj])
        {
            ans=true;
            return ;
        }else{
            dfs(edges,adj,visited,ans);
        }
        if(ans)
        {
            return ;
        }
    }
    visited[sv]=false;
}
int Solution::solve(int n, vector<vector<int> > &a) {
    vector<int> *edges=new vector<int>[n];
    int x,y;
    for(int i=0;i<(a.size());i++)
    {
        x=a[i][0];
        y=a[i][1];
        x--;y--;
        edges[x].push_back(y);
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=false;
            dfs(edges,i,visited,ans);
            if(ans)
            {
                return true;
            }
        }
    }
    return false;
}

****************************	SEE THIS APPROACH 		****************************
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    void checkCycle(vector<int> adj[],int sv,bool *visited,bool &ans,int par)
    {
        visited[sv]=true;
        for(int i=0;i<(adj[sv].size());i++)
        {
            int adjVertex=adj[sv][i];
            if(par==adjVertex)
            {
                continue;
            }
            if(visited[adjVertex])
            {
                ans=true;
                return ;
            }
            checkCycle(adj,adjVertex,visited,ans,sv);
            if(ans)
            {
                return ;
            }
        }
    }
	bool isCycle(int n, vector<int>adj[])
	{
	    bool *visited=new bool[n];
	    for(int i=0;i<n;i++)
	    {
	        visited[i]=false;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(!visited[i])
	        {
	            bool ans=false;
	            checkCycle(adj,i,visited,ans,-1);
	            if(ans)
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};

****************************	SEE THIS APPROACH (cycle detection digraph)	SOMETIMES TLE	****************************

void dfs(vector<int> *edges,int sv,int par,bool *visited,bool *cur_visited,bool &ans)
{
    visited[sv]=true;
    cur_visited[sv]=true;
    for(int i=0;i<(edges[sv].size());i++)
    {
        int adj=edges[sv][i];
        if(!visited[adj])
        {
            dfs(edges,adj,sv,visited,cur_visited,ans);
            if(ans)
            {
                return ;
            }
        }else{
            if(cur_visited[adj])
            {
                ans=true;
            }
        }
    }
    cur_visited[sv]=false;
}
int Solution::solve(int n, vector<int> &B, vector<int> &C) {
    int e=B.size();
    vector<int> *edges=new vector<int>[n];
    int x,y;
    for(int i=0;i<e;i++)
    {
        x=B[i];
        y=C[i];
        x--;y--;
        edges[x].push_back(y);
    }
    bool *visited=new bool[n];
    bool *cur_visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        cur_visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=false;
            dfs(edges,i,-1,visited,cur_visited,ans);
            if(ans)
            {
                return 0;
            }
        }
    }
    return 1;
}

