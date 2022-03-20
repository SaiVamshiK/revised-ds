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
        int size=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            size=max(size,nums[i]);
        }
        int *bit=new int[size+1];
        for(int i=0;i<=size;i++)
        {
            bit[i]=0;
        }
        vector<int> ans;
        ans.push_back(0);
        ins(bit,nums[n-1],size);
        for(int i=n-2;i>=0;i--)
        {
            int cur=nums[i];
            int temp=query(bit,cur-1);
            ans.push_back(temp);
            ins(bit,cur,size);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
