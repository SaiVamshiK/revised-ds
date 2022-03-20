void dfs(vector<int> *edges,int n,int sv,bool *visited,bool *cur,bool &ans)
{
    visited[sv]=true;
    cur[sv]=true;
    for(int i=0;i<(edges[sv].size());i++)
    {
        int adj=edges[sv][i];
        if(cur[adj])
        {
            ans=true;
        }else{
            dfs(edges,n,adj,visited,cur,ans);
        }
        if(ans)
        {
            return ;
        }
    }
    cur[sv]=false;
}
int Solution::solve(int n, vector<vector<int> > &vec) {
    vector<int> *edges=new vector<int>[n];
    for(int i=0;i<(vec.size());i++)
    {
        int x=vec[i][0],y=vec[i][1];
        x--;y--;
        edges[x].push_back(y);
    }
    bool *visited=new bool[n];
    bool *cur_visited_in_recursion=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        cur_visited_in_recursion[i]=false;
    }
    bool ans=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(edges,n,i,visited,cur_visited_in_recursion,ans);
            if(ans)
            {
                return 1;
            }
        }
    }
    return 0;
}

