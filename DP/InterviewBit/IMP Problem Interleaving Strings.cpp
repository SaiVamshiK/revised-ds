
Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.

bool func(string s1, string s2, string s3,int n,int m,int l,vector<vector<vector<int>>> &dp)
{
    if(l==0)
    {
        if(n==0&&(m==0))
        {
            return dp[n][m][l]=true;
        }
        return dp[n][m][l]=false;
    }
    if(n==0)
    {
        if(s2.substr(0,m)==(s3.substr(0,l)))
        {
            return dp[n][m][l]=true;
        }
        return dp[n][m][l]=false;
    }
    if(m==0)
    {
        if(s1.substr(0,n)==(s3.substr(0,l)))
        {
            return dp[n][m][l]=true;
        }
        return dp[n][m][l]=false;
    }
    if(dp[n][m][l]!=-1)
    {
        return dp[n][m][l];
    }
    if(s1[n-1]==s3[l-1]&&(s1[n-1]!=s2[m-1]))
    {
        bool op1=func(s1,s2,s3,n-1,m,l-1,dp);
        return dp[n][m][l]=op1;
    }else if((s2[m-1]==s3[l-1])&&(s1[n-1]!=s2[m-1]))
    {
        bool op1=func(s1,s2,s3,n,m-1,l-1,dp);
        return dp[n][m][l]=op1;
    }else if((s1[n-1]==s3[l-1])&&(s1[n-1]==s2[m-1]))
    {
        bool op1=func(s1,s2,s3,n-1,m,l-1,dp);
        bool op2=func(s1,s2,s3,n,m-1,l-1,dp);
        return dp[n][m][l]=(op1||(op2));
    }else{
        return dp[n][m][l]=false;
    }
}
int Solution::isInterleave(string s1, string s2, string s3) {
    int n=s1.size(),m=s2.size(),l=s3.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,-1)));
    return func(s1,s2,s3,n,m,l,dp);
}

