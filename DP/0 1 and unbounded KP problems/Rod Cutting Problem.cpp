
Given a rod of length N inches and an array of prices that contains prices of all pieces of size smaller than N. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.

// User function Template for C++
int func(int *a,int val[],int n,int sum,vector<vector<int>> &dp)
{
    if(n==0||(sum==0))
    {
        return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
        return dp[n][sum]=max(val[n-1]+func(a,val,n,sum-a[n-1],dp),func(a,val,n-1,sum,dp));
    }else{
        return dp[n][sum]=func(a,val,n-1,sum,dp);
    }
}
int cutRod(int val[], int n) {
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return func(a,val,n,n,dp);
}

