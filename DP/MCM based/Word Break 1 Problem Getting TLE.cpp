
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool func(string &s,int i,int j,unordered_set<string> &st,vector<vector<int>> &dp)
    {
        if(st.find(s.substr(i,j-i+1))!=st.end())
        {
            return true;
        }
        if(i==j)
        {
            return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int k=i;k<=(j-1);k++)
        {
            bool f1,f2;
            if(dp[i][k]!=-1)
            {
                f1=dp[i][k];
            }else{
                f1=func(s,i,k,st,dp);
                dp[i][k]=f1;
            }
            if(dp[k+1][j]!=-1)
            {
                f2=dp[k+1][j];
            }else{
                f2=func(s,k+1,j,st,dp);
                dp[k+1][j]=f2;
            }
            if(f1&&f2)
            {
                return true;
            }
        }
        return dp[i][j]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> st;
        for(int i=0;i<(wordDict.size());i++)
        {
            st.insert(wordDict[i]);
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        bool ans=func(s,0,n-1,st,dp);
        return ans;
    }
};
