
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

ROWS ARE START INDEXES AND COLUMNS ARE END INDEXES

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt++;
            dp[i][i]=true;
        }
        for(int i=0;i<(n-1);i++)
        {
            if(s[i]==s[i+1])
            {
                cnt++;
                dp[i][i+1]=true;   
            }else{
                dp[i][i+1]=false;
            }
        }
        for(int i=(n-3);i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(dp[i+1][j-1])
                    {
                        cnt++;
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return cnt;
    }
};
