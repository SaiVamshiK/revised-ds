const int MOD=1000007;
int func(vector<int> &a,int n,int sum,vector<vector<int>> &dp)
{
    if(sum==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum]%MOD;
    }
    if(a[n-1]<=sum)
    {
        int op1=func(a,n,sum-a[n-1],dp);
        int op2=func(a,n-1,sum,dp);
        return dp[n][sum]=((op1%MOD)+(op2%MOD))%MOD;
    }else{
        return dp[n][sum]=(func(a,n-1,sum,dp))%MOD;
    }
}
int Solution::coinchange2(vector<int> &a, int sum) {
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    return func(a,n,sum,dp);
}

