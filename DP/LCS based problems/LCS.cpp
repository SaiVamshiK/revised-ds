Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

******************************************
Recursive Approach


int func(string s1,string s2,int n,int m,int **dp)
{
    if(n==0||(m==0))
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=1+func(s1,s2,n-1,m-1,dp);
    }
    return dp[n][m]=max(func(s1,s2,n,m-1,dp),func(s1,s2,n-1,m,dp));
}
int lcs(int x, int y, string s1, string s2){
    int n=s1.size(),m=s2.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    return func(s1,s2,n,m,dp);
}




****************************************
Table Method


int lcs(int x, int y, string s1, string s2){
    int n=s1.size(),m=s2.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=1;j<=m;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}














