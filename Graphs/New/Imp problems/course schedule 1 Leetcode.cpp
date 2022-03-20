class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& vec) {
        int *in=new int[n];
        for(int i=0;i<n;i++)
        {
            in[i]=0;
        }
        vector<int> *edges=new vector<int>[n];
        int e=vec.size();
        for(int i=0;i<e;i++)
        {
            int x=vec[i][0],y=vec[i][1];
            edges[y].push_back(x);
            in[x]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            cnt++;
            int x=q.front();
            q.pop();
            for(int i=0;i<(edges[x].size());i++)
            {
                int adj=edges[x][i];
                in[adj]--;
                if(in[adj]==0)
                {
                    q.push(adj);
                }
            }
        }
        return cnt==n;
    }
};
