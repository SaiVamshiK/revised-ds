Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
public:
    void func(vector<int> &inp,int n,bool *visited,vector<int> &op,vector<vector<int>> &ans)
    {
        if(op.size()==n)
        {
            ans.push_back(op);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                op.push_back(inp[i]);
                visited[i]=true;
                func(inp,n,visited,op,ans);
                visited[i]=false;
                op.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<int> op;
        vector<vector<int>> ans;
        int n=a.size();
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        func(a,n,visited,op,ans);
        return ans;
    }
};
