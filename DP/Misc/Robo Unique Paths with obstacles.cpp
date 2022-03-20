
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        long n=a.size(),m=a[0].size();
        if(a[n-1][m-1]==1)
        {
            return 0;
        }
        vector<vector<long>> dp(n,vector<long>(m,0));
        dp[n-1][m-1]=1;
        for(long i=n-2;i>=0;i--)
        {
            if(a[i][m-1]==0)
            {
                dp[i][m-1]=1;
            }else{
                long x=i;
                for(long q=x;q>=0;q--)
                {
                    dp[q][m-1]=0;
                }
                break;
            }
        }
        for(long j=m-2;j>=0;j--)
        {
            if(a[n-1][j]==0)
            {
                dp[n-1][j]=1;
            }else{
                long x=j;
                for(long q=x;q>=0;q--)
                {
                    dp[n-1][q]=0;
                }
                break;
            }
        }
        for(long i=n-2;i>=0;i--)
        {
            for(long j=m-2;j>=0;j--)
            {
                if(a[i][j]==1)
                {
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};



















