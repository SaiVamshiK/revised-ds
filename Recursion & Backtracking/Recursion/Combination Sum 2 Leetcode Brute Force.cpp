
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
    void func(vector<int> &inp,int i,int n,vector<int> &op,int sum,set<vector<int>> &ans)
    {
        if(sum==0)
        {
            ans.insert(op);
            return ;
        }
        if(i==n)
        {
            return ;
        }
        int cur=inp[i];
        if(cur<=sum)
        {
            op.push_back(cur);
            func(inp,i+1,n,op,sum-cur,ans);
            op.pop_back();
            func(inp,i+1,n,op,sum,ans);
        }else{
            func(inp,i+1,n,op,sum,ans);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int sum) {
        sort(a.begin(),a.end());
        set<vector<int>> ans;
        int n=a.size();
        vector<int> op;
        func(a,0,n,op,sum,ans);
        vector<vector<int>> fin;
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            fin.push_back((*it));
        }
        return fin;
    }
};
