class Solution {
public:
    bool isBipartite(vector<vector<int>>& vec) {
        if(vec.empty())
        {
            return true;
        }
        unordered_set<int> sets[2];
        vector<int> pending;
        sets[0].insert(0);
        pending.push_back(0);
        while(pending.size()>0)
        {
            int x=pending.back();
            pending.pop_back();
            int cur_ele_set=(sets[0].count(x)>0)?0:1;
            if(vec[x].size()==0)
            {
                return false;
            }
            for(int i=0;i<(vec[x].size());i++)
            {
                int adj=vec[x][i];
                int a=sets[0].count(adj),b=sets[1].count(adj);
                if(a==0&&(b==0))
                {
                    sets[1-cur_ele_set].insert(adj);
                    pending.push_back(adj);
                }else{
                    if(sets[cur_ele_set].count(adj)>0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};








