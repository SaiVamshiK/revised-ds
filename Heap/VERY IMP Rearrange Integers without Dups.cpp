
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]


typedef pair<int,int> pi;
class Compare{
    public:
    bool operator()(pi a,pi b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& a) {
        int n=a.size();
        unordered_map<int,int > mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        priority_queue<pi,vector<pi>,Compare> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        vector<int> ans;
        int idx=0;
        while(!pq.empty())
        {
            pi temp1=pq.top();
            pq.pop();
            int temp1Val=temp1.second,temp1Freq=temp1.first;
            ans.push_back(temp1Val);
            temp1Freq--;
            if(temp1Freq!=0)
            {
                if(!pq.empty())
                {
                    pi temp2=pq.top();
                    pq.pop();
                    int temp2Val=temp2.second,temp2Freq=temp2.first;
                    ans.push_back(temp2Val);
                    temp2Freq--;
                    if(temp2Freq!=0)
                    {
                        pq.push({temp2Freq,temp2Val});
                    }
                    pq.push({temp1Freq,temp1Val});
                }else{
                    pq.push({temp1Freq,temp1Val});
                }
            }
        }
        return ans;
    }
};











