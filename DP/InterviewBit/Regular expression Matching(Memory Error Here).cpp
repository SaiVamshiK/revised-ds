Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return 0 or 1:
    => 0 : If the patterns do not match.
    => 1 : If the patterns match.
Constraints:

1 <= length(A), length(B) <= 9e4
Examples :

Input 1:
    A = "aa"
    B = "a"

Output 1:
    0

Input 2:
    A = "aa"
    B = "aa"

Output 2:
    1

Input 3:
    A = "aaa"
    B = "aa"

Output 3:
    0
    
Input 4:
    A = "aa"
    B = "*"

Output 4:
    1

bool func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(n==0)
    {
        if(m==0)
        {
            return true;
        }
        for(int i=0;i<m;i++)
        {
            if(s2[i]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(m==0)
    {
        return false;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        bool op1=func(s1,s2,n-1,m-1,dp);
        return dp[n][m]=op1;
    }else{
        if(s2[m-1]=='*')
        {
            bool op1=func(s1,s2,n,m-1,dp);
            bool op2=func(s1,s2,n-1,m-1,dp);
            bool op3=func(s1,s2,n-1,m,dp);
            return dp[n][m]=op1||(op2)||(op3);
        }else if(s2[m-1]=='?')
        {
            bool op=func(s1,s2,n-1,m-1,dp);
            return dp[n][m]=op;
        }else{
            return dp[n][m]=false;
        }
    }
}
int Solution::isMatch(const string s1, const string s2) {
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return func(s1,s2,n,m,dp);
}

