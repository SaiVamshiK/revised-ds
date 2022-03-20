
There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.


int findMin(int row,int col,vector<vector<int> > &a,int n,int m,vector<vector<int>> &dp)
{
    if(row==n)
    {
        return 0;
    }
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    int ans=INT_MAX;
    for(int j=0;(j<m);j++)
    {
        if(j==col)
        {
            continue ;
        }
        int cur=a[row][j];
        ans=min(ans,cur+findMin(row+1,j,a,n,m,dp));
    }
    return dp[row][col]=ans;
}
int Solution::solve(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int ans=INT_MAX;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<m;i++)
    {
        int cur=a[0][i];
        ans=min(ans,cur+findMin(1,i,a,n,m,dp));
    }
    return ans;
}

