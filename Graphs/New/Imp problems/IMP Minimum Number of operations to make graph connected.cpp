There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 
***************
Using concept of REDUNDANT EDGES

class Solution {
public:
    void dfs(vector<int> *edges,int sv,bool *visited,int &edge_cnt,int &node_cnt)
    {
        visited[sv]=true;
        node_cnt++;
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            edge_cnt++;
            if(!visited[adj])
            {
                dfs(edges,adj,visited,edge_cnt,node_cnt);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& vec) {
        vector<int> *edges=new vector<int>[n];
        for(int i=0;i<(vec.size());i++)
        {
            int x=vec[i][0],y=vec[i][1];
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        bool *visited=new bool[n];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        int components=0;
        int redundant_edges=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int edge_cnt=0,node_cnt=0;
                dfs(edges,i,visited,edge_cnt,node_cnt);
                edge_cnt/=2;
                if((node_cnt-1)!=edge_cnt)
                {
                    redundant_edges+=(edge_cnt-node_cnt+1);
                }
                components++;
            }
        }
        if(components==1)
        {
            return 0;
        }
        if(redundant_edges>=(components-1))
        {
            return components-1;
        }
        return -1;
    }
};
