class Solution {
public:
    void swap(int &a,int &b)
    {
        int t;
        t=a;
        a=b;
        b=t;
    }
    void func(vector<int> &inp,int idx,int n,vector<vector<int>> &ans)
    {
        if(idx==n)
        {
            ans.push_back(inp);
            return ;
        }
        for(int i=idx;i<n;i++)
        {
            swap(inp[idx],inp[i]);
            func(inp,idx+1,n,ans);
            swap(inp[idx],inp[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> op;
        vector<vector<int>> ans;
        func(nums,0,n,ans);
        return ans;
    }
};
