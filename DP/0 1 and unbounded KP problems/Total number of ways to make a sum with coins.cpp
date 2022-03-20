Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

************** SEE THIS APPROACH **************

typedef long long int ll;

class Solution
{
  public:
    ll func(int a[],int n,int sum,vector<vector<ll>> &dp)
    {
        if(sum==0)
        {
            return 1;
        }
        if(n==0)
        {
            return INT_MIN;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(a[n-1]<=sum)
        {
            ll op1=func(a,n,sum-a[n-1],dp);
            ll op2=func(a,n-1,sum,dp);
            if(op1!=INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][sum]=op1+op2;
            }else if(op1!=INT_MIN&&(op2==INT_MIN))
            {
                return dp[n][sum]=op1;
            }else if(op1==INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][sum]=op2;
            }else{
                return dp[n][sum]=INT_MIN;
            }
        }else{
            ll op1=func(a,n-1,sum,dp);
            if(op1!=INT_MIN)
            {
                return dp[n][sum]=op1;
            }
            return dp[n][sum]=INT_MIN;
        }
    }
    long long int count(int a[],int n,int sum)
    {
        vector<vector<ll>> dp(n+1,vector<ll>(sum+1,-1));
        ll ans=func(a,n,sum,dp);
        return (ans!=INT_MIN)?ans:0;
    }
};

*********************************
Unbounded Knapsack Problem

typedef long long int ll;
class Solution
{
  public:
    ll func(int a[],int n,int sum,ll **dp)
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
        }return dp[n][sum]=func(a,n-1,sum,dp);
    }
    long long int count( int a[], int n, int sum )
    {
        ll **dp=new ll*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new ll[sum+1];
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=-1;
            }
        }
        return func(a,n,sum,dp);
    }
};


