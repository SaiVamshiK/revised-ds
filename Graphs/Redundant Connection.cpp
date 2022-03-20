
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge 
between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, 
return the answer that occurs last in the input.

class Solution {
public:
    int getParent(int *parent,int i)
    {
        if(i==parent[i])
        {
            return i;
        }
        return parent[i]=getParent(parent,parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& a) {
        int n=a.size();
        int *parent=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int x,y;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            x=a[i][0];
            y=a[i][1];
            x--;y--;
            int xPar=getParent(parent,x),yPar=getParent(parent,y);
            if(xPar==yPar)
            {
                ans.push_back(x+1);
                ans.push_back(y+1);
                break;
            }else{
                parent[xPar]=yPar;
            }
        }
        return ans;
    }
};
