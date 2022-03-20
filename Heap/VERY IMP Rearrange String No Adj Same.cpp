
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""

typedef pair<int,char> pi;
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pi> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        string ans="";
        while(!pq.empty())
        {
            pi top1=pq.top();
            pq.pop();
            int cur_freq=top1.first;
            char cur_ch=top1.second;
            ans.push_back(cur_ch);
            cur_freq--;
            if(cur_freq!=0)
            {
                if(pq.empty())
                {
                    return "";
                }
                pi top2=pq.top();
                pq.pop();
                int cur_freq_1=top2.first;
                char cur_ch_1=top2.second;
                ans.push_back(cur_ch_1);
                cur_freq_1--;
                if(cur_freq_1==0)
                {
                    pq.push({cur_freq,cur_ch});
                }else{
                    pq.push({cur_freq,cur_ch});
                    pq.push({cur_freq_1,cur_ch_1});
                }
            }
        }
        return ans;
    }
};
