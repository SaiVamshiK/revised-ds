class Solution {
public:
    bool startColouring(vector<vector<int>>& vec,int sv,int *color,int cur_color)
    {
        queue<int> q;
        q.push(sv);
        color[sv]=cur_color;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            int cur_ele_color=color[x];
            for(int i=0;i<(vec[x].size());i++)
            {
                int adj=vec[x][i];
                if(color[adj]==cur_ele_color)
                {
                    return false;
                }else{
                    if(color[adj]==-1)
                    {
                        color[adj]=1-cur_ele_color;
                        q.push(adj);
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& vec) {
        if(vec.empty())
        {
            return true;
        }
        int n=vec.size();
        int *color=new int[n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                bool temp=startColouring(vec,i,color,0);
                if(!temp) return temp;
            }
        }
        return true;
    }
};








