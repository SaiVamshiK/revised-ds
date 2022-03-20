Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	void dfs(vector<int> adj[],int sv,bool *visited,bool *cur_visited,bool &ans)
	{
	    visited[sv]=true;
	    cur_visited[sv]=true;
	    for(int i=0;i<(adj[sv].size());i++)
	    {
	        int adjElem=adj[sv][i];
	        if(cur_visited[adjElem])
	        {
	            ans=true;
	            return ;
	        }else{
	            dfs(adj,adjElem,visited,cur_visited,ans);
	        }
	        if(ans)
	        {
	            return ;
	        }
	    }
	    cur_visited[sv]=false;
	}
	bool isCyclic(int n, vector<int> adj[]) 
	{
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
                dfs(adj,i,visited,cur_visited,ans);
                if(ans)
                {
                    return true;
                }
            }
        }
        return false;
	}
};
