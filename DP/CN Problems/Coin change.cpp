For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.

int func(int a[],int n,int sum,int **dp)
{
	if(sum==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
        return dp[n][sum]=func(a,n,sum-a[n-1],dp)+func(a,n-1,sum,dp);
    }else{
        return dp[n][sum]=func(a,n-1,sum,dp);
    }
}
int countWaysToMakeChange(int a[], int n, int sum){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=-1;
        }
    }
    return func(a,n,sum,dp);
}

















