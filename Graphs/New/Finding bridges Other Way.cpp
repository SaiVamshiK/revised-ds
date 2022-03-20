class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> *edges,int sv,int par,bool *visited,int *discovered,int *lowest,int &timer)
    {
        visited[sv]=true;
        discovered[sv]=timer;
        lowest[sv]=timer;
        timer++;
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            if(!visited[adj])
            {
                dfs(edges,adj,sv,visited,discovered,lowest,timer);
                lowest[sv]=min(lowest[sv],lowest[adj]);
            }else{
                if(adj!=par)
                {
                    // back-edge
                    lowest[sv]=min(lowest[sv],discovered[adj]);
                }
            }
            if(lowest[adj]>discovered[sv])
            {
                ans.push_back({adj,sv});
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
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        int *lowest=new int[n];
        int *discovered=new int[n];
        int timer=1;
        dfs(edges,0,-1,visited,discovered,lowest,timer);
        return ans;
    }
};













