Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    bool isUnique(unordered_map<char,int> mp)
    {
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if((it->second)>1)
            {
                return false;
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0||n==1)
        {
            return n;
        }
        int ans=INT_MIN;
        int i=0,j=0;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            if(isUnique(mp))
            {
                ans=max(ans,j-i+1);
                j++;
            }else{
                while(true)
                {
                    char cur_ch=s[i];
                    auto itr=mp.find(cur_ch);
                    int cur_ch_freq=itr->second;
                    mp.erase(itr);
                    cur_ch_freq--;
                    if(cur_ch_freq==1)
                    {
                        mp.insert({cur_ch,1});
                        i++;
                        break;
                    }
                    i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};
