
Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. 
If two numbers have the same frequency then the larger number should be given preference. 

Example 1:

Input:
nums = {1,1,1,2,2,3},
k = 2
Output: {1, 2}

typedef pair<int,int> pi;
class Compare{
    public:
    bool operator()(pi a,pi b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};

// > => Min Heap
// > => Min Heap

class Solution{
  public:
    vector<int> topK(vector<int>& a, int k) {
        int n=a.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        priority_queue<pi,vector<pi>,Compare> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
