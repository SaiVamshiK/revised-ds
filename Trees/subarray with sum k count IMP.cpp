class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            a[i]+=a[i-1];
        }
        unordered_map<int,int> mp;
        mp[0]++;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i]-k)!=mp.end())
            {
                ans+=mp[a[i]-k];
            }
            mp[a[i]]++;
        }
        return ans;
    }
};
