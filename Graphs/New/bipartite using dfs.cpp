********************************************** See This Approach	**********************************************
class Solution {
public:
    void dfs(vector<vector<int>> &edges,int sv,int set_no,unordered_set<int> *sets,bool *visited,bool &ans)
    {
        visited[sv]=true;
        sets[set_no].insert(sv);
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            if(!visited[adj])
            {
                dfs(edges,adj,1-set_no,sets,visited,ans);
            }else{
                int x=(sets[0].count(adj)>0)?0:1;
                if(x==set_no)
                {
                    ans=true;
                }
            }
            if(ans)
            {
                return ;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& edges) {
        int n=edges.size();
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                unordered_set<int> *sets=new unordered_set<int>[2];
                bool ans=false;
                dfs(edges,i,0,sets,visited,ans);
                if(ans)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

void startColouring(vector<int> *edges,int sv,int *color,int cur_color,bool &ans)
{
    color[sv]=cur_color;
    for(int i=0;i<(edges[sv].size());i++)
    {
        int adj=edges[sv][i];
        if(color[adj]==cur_color)
        {
            ans=false;
        }else{
            if(color[adj]==-1)
            {
                startColouring(edges,adj,color,1-cur_color,ans);
            }
        }
        if(!ans) 
        {
            return ;
        }
    }
}
int Solution::solve(int n, vector<vector<int> > &vec) {
    if(n==0)
    {
        return true;
    }
    vector<int> *edges=new vector<int>[n];
    for(int i=0;i<vec.size();i++)
    {
        int x=vec[i][0],y=vec[i][1];
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);
    }
    int *color=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            bool done=true;
            startColouring(edges,i,color,0,done);
            if(!done)
            {
                return false;
            }
        }
    }
    return true;
}


