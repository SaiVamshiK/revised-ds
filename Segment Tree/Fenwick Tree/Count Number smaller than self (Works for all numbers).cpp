class Solution {
public:
    void ins(int *bit,int i,int n)
    {
        for(;i<=n;i+=(i&(-i)))
        {
            bit[i]++;
        }
    }
    int query(int *bit,int i)
    {
        int ans=0;
        for(;i>0;i-=(i&(-i)))
        {
            ans+=bit[i];
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        unordered_map<int,int > mp;
        int val=0;
        for(auto it=st.begin();it!=st.end();it++)
        {
            mp[(*it)]=++val;
        }
        int n=val;
        int *bit=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            bit[i]=0;
        }
        vector<int> ans;
        ans.push_back(0);
        ins(bit,mp[nums[(nums.size())-1]],n);
        for(int i=(nums.size()-2);i>=0;i--)
        {
            int cur=mp[nums[i]];
            int temp=query(bit,cur-1);
            ans.push_back(temp);
            ins(bit,cur,n);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
