class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> *edges,int cur,int par,int *lowest,int *discovered,int &timer,bool *visited)
    {
        visited[cur]=true;
        lowest[cur]=timer;
        discovered[cur]=timer;
        timer++;
        for(int i=0;i<(edges[cur].size());i++)
        {
            int adj=edges[cur][i];
            if(visited[adj])
            {
                if(adj!=par)
                {
                    // back edge
                    lowest[cur]=min(lowest[cur],discovered[adj]);   
                }
            }else{
                dfs(edges,adj,cur,lowest,discovered,timer,visited);
                lowest[cur]=min(lowest[cur],lowest[adj]);
            }
            if(lowest[adj]>discovered[cur])
            {
                ans.push_back({cur,adj});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& vec) {
        vector<int> *edges=new vector<int>[n];
        for(int i=0;i<(vec.size());i++)
        {
            int x=vec[i][0],y=vec[i][1];
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int *lowest=new int[n];
        int *discovered=new int[n];
        int timer=1;
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        dfs(edges,0,-1,lowest,discovered,timer,visited);
        return ans;
    }
};







