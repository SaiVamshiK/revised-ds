
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
 
***************************************
VISITED ARRAY METHOD
***************************************

class Solution {
public:
    void func(vector<int> &inp,bool *visited,int n,vector<int> &op,vector<vector<int>> &ans)
    {
        if(op.size()==n)
        {
            ans.push_back(op);
            return ;
        }
        int prev=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(!visited[i]&&(inp[i]!=prev))
            {
                visited[i]=true;
                op.push_back(inp[i]);
                func(inp,visited,n,op,ans);
                op.pop_back();
                visited[i]=false;
                prev=inp[i];
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        vector<int> op;
        vector<vector<int>> ans;
        func(a,visited,n,op,ans);
        return ans;
    }
};
