Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 ? 3 ? 1 ? 1 ? 1 minimizes the sum.


class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[n-1][m-1]=a[n-1][m-1];
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1][i]=dp[n-1][i+1]+a[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            dp[i][m-1]=dp[i+1][m-1]+a[i][m-1];
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

class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[m];
        }
        dp[0][0]=a[0][0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=a[i][0]+dp[i-1][0];
        }
        for(int j=1;j<m;j++)
        {
            dp[0][j]=a[0][j]+dp[0][j-1];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // up={i-1,j}
                // left={i,j-1}
                if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=a[i][j]+dp[i-1][j];
                }else{
                    dp[i][j]=a[i][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
