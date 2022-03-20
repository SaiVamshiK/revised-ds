There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

typedef pair<int,int> pi;
class Solution {
public:
    void dfs(vector<int> *edges,int sv,vector<bool> &visited,set<pi> &st,int &cnt)
    {
        visited[sv]=true;
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            if(!visited[adj])
            {
                if(st.find({adj,sv})==st.end())
                {
                    cnt++;
                }
                dfs(edges,adj,visited,st,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pi> st;
        for(int i=0;i<(connections.size());i++)
        {
            st.insert({connections[i][0],connections[i][1]});
        }
        vector<int> *edges=new vector<int>[n];
        int x,y;
        for(int i=0;i<(connections.size());i++)
        {
            x=connections[i][0];
            y=connections[i][1];
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        vector<bool> visited(n,false);
        int cnt=0;
        dfs(edges,0,visited,st,cnt);
        return cnt;
    }
};
