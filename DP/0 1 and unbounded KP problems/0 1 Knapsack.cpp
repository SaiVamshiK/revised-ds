
// Returns the maximum value that  
// can be put in a knapsack of capacity W 
************************
Recursion Method
int func(int W,int wt[],int val[],int n,int **dp)
{
    if(n==0||(W==0))
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1]<=W)
    {
        return dp[n][W]=max(func(W-wt[n-1],wt,val,n-1,dp)+val[n-1],func(W,wt,val,n-1,dp));
    }else{
        return dp[n][W]=func(W,wt,val,n-1,dp);
    }
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[W+1];
        for(int j=0;j<=W;j++)
        {
            dp[i][j]=-1;
        }
    }
    return func(W,wt,val,n,dp);
}

**********
Table Method

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[W+1];
        for(int j=0;j<=W;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=W;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

