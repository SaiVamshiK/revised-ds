class Solution {
public:
    void func(vector<int> &a,int idx,int n,vector<vector<int>> &ans)
    {
        if(idx==n)
        {
            ans.push_back(a);
            return ;
        }
        for(int i=idx;i<n;i++)
        {
            swap(a[idx],a[i]);
            func(a,idx+1,n,ans);
            swap(a[idx],a[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> ans;
        func(a,0,n,ans);
        return ans;
    }
};
