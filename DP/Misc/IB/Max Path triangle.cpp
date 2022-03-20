
Given a 2D integer array A of size  N * N  representing a triangle of numbers.

Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

NOTE:

Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
Row i contains i integer and n-i zeroes for all i in [1,n] where zeroes represents empty cells.


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
    if(col+1<=(row+1))
    {
        int op2=func(a,row+1,col+1,n,dp);
        return dp[row][col]=max(op1,op2)+a[row][col];
    }else{
        return dp[row][col]=op1+a[row][col];
    }
}
int Solution::solve(vector<vector<int> > &a) {
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return func(a,0,0,n,dp);
}

