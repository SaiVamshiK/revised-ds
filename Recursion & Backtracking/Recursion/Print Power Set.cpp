
Share
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

class Solution {
public:
    vector<vector<int>> ans; 
    void func(vector<int> &inp,int i,int n,vector<int> op)
    {
        if(i==n)
        {
            ans.push_back(op);
            return ;
        }
        func(inp,i+1,n,op);
        op.push_back(inp[i]);
        func(inp,i+1,n,op);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        int n=a.size();
        vector<int> op;
        func(a,0,n,op);
        return ans;
    }
};
