
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int len=0,start,end;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            if(len<(dp[i][i]))
            {
                len=dp[i][i];
                start=i;
                end=i;
            }
        }
        for(int i=0;i<(n-1);i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=2;
                if(len<(dp[i][i+1]))
                {
                    len=dp[i][i+1];
                    start=i;
                    end=i+1;
                }
            }
        }
        for(int i=n-3;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=2+dp[i+1][j-1];
                        if(len<(dp[i][j]))
                        {
                            len=dp[i][j];
                            start=i;
                            end=j;
                        }
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
