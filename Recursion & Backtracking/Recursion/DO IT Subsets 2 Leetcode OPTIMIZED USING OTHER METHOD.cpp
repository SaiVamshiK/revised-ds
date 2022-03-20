
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution {
public:
    void func(vector<int> &inp,int idx,int n,vector<int> &op,vector<vector<int>> &ans)
    {
        if(idx==n)
        {
            return ;
        }
        int prev=INT_MIN;
        for(int i=idx;i<n;i++)
        {
            int cur=inp[i];
            if(prev!=cur)
            {
                op.push_back(cur);
                func(inp,i+1,n,op,ans);
                ans.push_back(op);
                op.pop_back();
                prev=cur;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> op;
        vector<vector<int>> ans;
        ans.push_back(op);
        func(nums,0,n,op,ans);
        return ans;
    }
};
