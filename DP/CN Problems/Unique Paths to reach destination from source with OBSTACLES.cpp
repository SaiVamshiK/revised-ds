
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        if(a[n-1][m-1]==1)
        {
            return 0;
        }
        vector<vector<long>> dp(n,vector<long>(m));
        dp[n-1][m-1]=1;
        for(int i=m-2;i>=0;i--)
        {
            if(a[n-1][i]==1)
            {
                while(i>=0)
                {
                    dp[n-1][i]=0;
                    i--;
                }
                break;
            }else{
                dp[n-1][i]=1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(a[i][m-1]==1)
            {
                while(i>=0)
                {
                    dp[i][m-1]=0;
                    i--;
                }
                break;
            }else{
                dp[i][m-1]=1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
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

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[m];
        }
        if(a[0][0]==1||(a[n-1][m-1]==1))
        {
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i][0]==0)
            {
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][0]=0;
            }
        }
        for(int j=1;j<m;j++)
        {
            if(a[0][j]==0)
            {
                dp[0][j]=dp[0][j-1];
            }else{
                dp[0][j]=0;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};




















