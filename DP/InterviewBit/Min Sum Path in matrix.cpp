Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time.



Input Format
First and only argument is an 2D integer array A of size M x N.



Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

int Solution::minPathSum(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
    }
    dp[n-1][m-1]=a[n-1][m-1];
    for(int i=m-2;i>=0;i--)
    {
        dp[n-1][i]=a[n-1][i]+dp[n-1][i+1];
    }
    for(int i=n-2;i>=0;i--)
    {
        dp[i][m-1]=a[i][m-1]+dp[i+1][m-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            dp[i][j]=a[i][j]+min(dp[i][j+1],dp[i+1][j]);
        }
    }
    return dp[0][0];
}



