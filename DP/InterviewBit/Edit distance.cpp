int func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(n==0)
    {
        return m;
    }
    if(m==0)
    {
        return n;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=func(s1,s2,n-1,m-1,dp);
    }else{
        int op1=func(s1,s2,n-1,m-1,dp)+1;
        int op2=func(s1,s2,n,m-1,dp)+1;
        int op3=func(s1,s2,n-1,m,dp)+1;
        return dp[n][m]=min(op1,min(op2,op3));
    }
}

int Solution::minDistance(string s1, string s2) {
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return func(s1,s2,n,m,dp);
}

