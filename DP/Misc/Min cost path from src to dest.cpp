
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[n-1][m-1]=a[n-1][m-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i][m-1]=a[i][m-1]+dp[i+1][m-1];
        }
        for(int j=m-2;j>=0;j--)
        {
            dp[n-1][j]=a[n-1][j]+dp[n-1][j+1];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
