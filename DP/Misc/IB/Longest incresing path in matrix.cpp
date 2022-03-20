
Problem Description

Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.


int Solution::solve(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[n-1][m-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i][m-1]<(a[i+1][m-1]))
        {
            dp[i][m-1]=1+dp[i+1][m-1];
        }else{
            int x=i;
            while(x>=0)
            {
                dp[x][m-1]=-1;
                x--;
            }
            break;
        }
    }
    for(int i=m-2;i>=0;i--)
    {
        if(a[n-1][i]<(a[n-1][i+1]))
        {
            dp[n-1][i]=1+dp[n-1][i+1];
        }else{
            int x=i;
            while(x>=0)
            {
                dp[n-1][x]=-1;
                x--;
            }
            break;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            int cur=a[i][j];
            dp[i][j]=-1;
            if(cur<a[i+1][j])
            {
                if(dp[i+1][j]!=-1)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j]);
                }
            }
            if(cur<a[i][j+1])
            {
                if(dp[i][j+1]!=-1)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i][j+1]);
                }
            }
        }
    }
    return dp[0][0];
}

