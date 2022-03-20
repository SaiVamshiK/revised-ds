
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of 
candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at 
least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
****************************************
All elements are unique here so a list of elements that make up to the sum are unique sets no repetition will be there so we may not use set (this reduces TC)
***************************************
class Solution {
public:
    void func(vector<int> &inp,int i,int n,int sum,vector<int> &op,vector<vector<int>> &ans)
    {
        if(sum==0)
        {
            ans.push_back(op);
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
            func(inp,i,n,sum-cur,op,ans);
            op.pop_back();
            func(inp,i+1,n,sum,op,ans);
        }else{
            func(inp,i+1,n,sum,op,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n=a.size();
        vector<vector<int>> ans;
        vector<int> op;
        func(a,0,n,target,op,ans);
        return ans;
    }
};











