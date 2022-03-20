void dfs(vector<int> *edges,int n,bool *visited,int sv,int parent,bool &done)
{
    visited[sv]=true;
    for(int i=0;i<(edges[sv].size());i++)
    {
        int adj=edges[sv][i];
        if(!visited[adj])
        {
            dfs(edges,n,visited,adj,sv,done);
        }else{
            if(parent!=adj)
            {
                done=true;
            }
        }
        if(done)
        {
            return ;
        }
    }
}
int Solution::solve(int n, vector<vector<int> > &B) {
    vector<int> *edges=new vector<int>[n];
    int m=B.size();
    for(int i=0;i<m;i++)
    {
        int a=B[i][0],b=B[i][1];
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    bool done=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(edges,n,visited,i,-1,done);
        }
        if(done)
        {
            return done;
        }
    }
    return done;
}


