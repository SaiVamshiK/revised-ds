
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

int Solution::uniquePathsWithObstacles(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
        }
    }
    if(a[n-1][m-1]==1)
    {
        return 0;
    }
    dp[n-1][m-1]=1;
    for(int i=m-2;i>=0;i--)
    {
        if(a[n-1][i]==0)
        {
            dp[n-1][i]=1;
        }else{
            while(i>=0)
            {
                dp[n-1][i]=0;
                i--;
            }
            break;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i][m-1]==0)
        {
            dp[i][m-1]=1;
        }else{
            while(i>=0)
            {
                dp[i][m-1]=0;
                i--;
            }
            break;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            if(a[i][j]==0)
            {
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }else{
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}

