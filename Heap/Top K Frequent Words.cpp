
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, 
then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order

typedef pair<int,string> pi;
class Compare{
    public:
    bool operator()(pi a,pi b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        return a.second<b.second;
    }
};
// < => Max Heap
// > => Min Heap
class Solution {
public:
    vector<string> topKFrequent(vector<string>& a, int k) {
        int n=a.size();
        unordered_map<string,int> mp;
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
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
