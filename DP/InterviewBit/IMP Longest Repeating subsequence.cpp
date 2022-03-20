int func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(n==0||(m==0))
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if((n-1!=(m-1))&&(s1[n-1]==s2[m-1]))
    {
        return dp[n][m]=1+func(s1,s2,n-1,m-1,dp);
    }else{
        return dp[n][m]=max(func(s1,s2,n-1,m,dp),func(s1,s2,n,m-1,dp));
    }
}
int Solution::anytwo(string s1) {
    string s2=s1;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=func(s1,s2,n,m,dp);
    if(ans>=2)
    {
        return true;
    }
    return false;
}

