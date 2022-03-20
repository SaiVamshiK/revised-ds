#include<bits/stdc++.h>
int func(int *a,int *val,int n,int sum,vector<vector<int>> &dp)
{
    if(sum==0)
    {
        return 0;
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
        return dp[n][sum]=max(func(a,val,n-1,sum-a[n-1],dp)+val[n-1],func(a,val,n-1,sum,dp));
    }else{
        return dp[n][sum]=func(a,val,n-1,sum,dp);
    }
}
int knapsack(int* a, int* val, int n, int sum) {
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	return func(a,val,n,sum,dp);
}
