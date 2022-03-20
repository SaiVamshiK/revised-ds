
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

int func(vector<vector<int>> &a,int row,int col,int n,vector<vector<int>> &dp)
{
    if(row==n)
    {
        return 0;
    }
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    // row+1,col
    int op1=func(a,row+1,col,n,dp);
    // row+1,col+1
    if((col+1)<=(row+1))
    {
        int op2=func(a,row+1,col+1,n,dp);
        return dp[row][col]=min(op1,op2)+a[row][col];
    }
    return dp[row][col]=op1+a[row][col];
}

int Solution::minimumTotal(vector<vector<int> > &a) {
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return func(a,0,0,n,dp);
}

