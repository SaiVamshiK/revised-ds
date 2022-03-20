
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m));
        dp[n-1][m-1]=1;
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1][i]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            dp[i][m-1]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int uniquePaths(int n, int m) {
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[m];
        }
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        for(int j=1;j<m;j++)
        {
            dp[0][j]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
