Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

class Solution {
public:
    void func(vector<int> &inp,int idx,int n,int sum,vector<int> &op,vector<vector<int>> &ans)
    {
        if(sum==0)
        {
            ans.push_back(op);
            return ;
        }
        if(idx==n)
        {
            return ;
        }
        int prev=-1;
        for(int i=idx;i<n;i++)
        {
            int cur=inp[i];
            if(cur>sum)
            {
                break;
            }
            if(prev!=cur)
            {
                op.push_back(cur);
                func(inp,i+1,n,sum-cur,op,ans);
                op.pop_back();
                prev=cur;
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int sum) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        vector<int> op;
        int n=a.size();
        func(a,0,n,sum,op,ans);
        return ans;
    }
};
