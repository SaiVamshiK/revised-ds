
There are A coins (Assume A is even) in a line.

Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

The player with the larger amount of money wins, Assume that you go first.

Return the maximum amount of money you can win.

NOTE:

You can assume that opponent is clever and plays optimally.


int func(vector<int> &a,int l,int r,vector<vector<int>> &dp)
{
    if(l==r)
    {
        return a[l];
    }
    if(l>r)
    {
        return 0;
    }
    int f1;
    if(dp[l+2][r]!=-1)
    {
        f1=dp[l+2][r];
    }else{
        f1=func(a,l+2,r,dp);
    }
    int f2;
    if(dp[l+1][r-1]!=-1)
    {
        f2=dp[l+1][r-1];
    }else{
        f2=func(a,l+1,r-1,dp);
    }
    int op1=a[l]+min(f1,f2);
    
    int f3;
    if(dp[l+1][r-1]!=-1)
    {
        f3=dp[l+1][r-1];
    }else{
        f3=func(a,l+1,r-1,dp);
    }
    int f4;
    if(dp[l][r-2]!=-1)
    {
        f4=dp[l][r-2];
    }else{
        f4=func(a,l,r-2,dp);
    }
    int op2=a[r]+min(f3,f4);
    
    return dp[l][r]=max(op1,op2);
}
int Solution::maxcoin(vector<int> &a) {
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return func(a,0,n-1,dp);
}

