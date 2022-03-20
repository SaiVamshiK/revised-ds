A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.

long func(int n,long *dp)
{
    if(n==0)
    {
        return dp[n]=0;
    }
    if(n==1)
    {
        return dp[n]=1;
    }
    if(n==2)
    {
        return dp[n]=2;
    }
    if(n==3)
    {
        return dp[n]=4;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=func(n-1,dp)+func(n-2,dp)+func(n-3,dp);
}
long staircase(int n)
{
    long *dp=new long[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
	return func(n,dp);
}








