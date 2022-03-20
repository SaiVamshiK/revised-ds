Given two strings s and t, check if s is a subsequence of t.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

class Solution {
public:
    bool func(string s1,string s2,int n,int m)
    {
        if(n==0)
        {
            return true;
        }
        if(m==0)
        {
            return false;
        }
        if(s1[n-1]==s2[m-1])
        {
            return func(s1,s2,n-1,m-1)||(func(s1,s2,n,m-1));
        }
        return func(s1,s2,n,m-1);
    }
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        bool **dp=new bool*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new bool[m+1];
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=true;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]||(dp[i][j-1]);
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
