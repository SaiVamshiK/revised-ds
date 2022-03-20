You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

***
actually djsktra can be used but some vertices have 0 weight so to handle them floyd warshall is used.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& vec, int n, int x) {
        x--;
        int e=vec.size();
        int **edges=new int*[n];
        for(int i=0;i<n;i++)
        {
            edges[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                edges[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<e;i++)
        {
            int x=vec[i][0],y=vec[i][1],z=vec[i][2];
            x--;y--;
            edges[x][y]=z;
        }
        for(int i=0;i<n;i++)
        {
            edges[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if((edges[k][j]!=INT_MAX)&&(edges[i][k]!=INT_MAX)&&edges[i][j]>(edges[i][k]+edges[k][j]))
                    {
                        edges[i][j]=edges[i][k]+edges[k][j];
                    }
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(edges[x][i]==INT_MAX)
            {
                return -1;
            }
            ans=max(ans,edges[x][i]);
        }
        return ans;
    }
};
