You are given a set of N integers. You have to return true if there exists a subset that sum up to K, otherwise return false.


bool func(int *a,int n,int sum,int **dp)
{
    if(sum==0)
    {
        return true;
    }
    if(n==0)
    {
        return false;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum) 
    {
        return dp[n][sum]=func(a,n-1,sum-a[n-1],dp)||(func(a,n-1,sum,dp));
    }else{
        return dp[n][sum]=func(a,n-1,sum,dp);
    }
}
bool isSubsetPresent(int *arr, int n, int sum)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=-1;
        }
    }
    return func(arr,n,sum,dp);
}
