
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections 
forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. 
Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other 
server.

Return all critical connections in the network in any order.

class Solution {
public:
    void dfs(vector<int> *edges,int sv,int par,int *disc,int *lowest,int &timer,vector<vector<int>> &ans)
    {
        disc[sv]=timer;
        lowest[sv]=timer;
        timer++;
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            if(disc[adj]==-1)
            {
                // unvisited
                dfs(edges,adj,sv,disc,lowest,timer,ans);
                lowest[sv]=min(lowest[sv],lowest[adj]);
            }else{
                if(par!=adj)
                {
                    lowest[sv]=min(lowest[sv],disc[adj]);
                }
            }
            if(lowest[adj]>disc[sv])
            {
                ans.push_back({adj,sv});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& a) {
        vector<int> *edges=new vector<int>[n];
        int e=a.size();
        int x,y;
        for(int i=0;i<e;i++)
        {
            x=a[i][0];
            y=a[i][1];
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int *disc=new int[n];
        int *lowest=new int[n];
        for(int i=0;i<n;i++)
        {
            disc[i]=-1;
        }
        int timer=1;
        vector<vector<int>> ans;
        dfs(edges,0,-1,disc,lowest,timer,ans);
        return ans;
    }
};












