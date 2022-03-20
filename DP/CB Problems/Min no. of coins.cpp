
https://leetcode.com/problems/coin-change/
class Solution {
public:
    int func(vector<int>& a,int n,int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return 0;
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
            int op1=func(a,n,sum-a[n-1],dp);
            int op2=func(a,n-1,sum,dp);
            if(op1!=INT_MIN&&(op2==INT_MIN))
            {
                return dp[n][sum]=1+op1;
            }
            if(op1==INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][sum]=op2;
            }
            if(op1==INT_MIN&&(op2==INT_MIN))
            {
                return dp[n][sum]=INT_MIN;
            }
            return dp[n][sum]=min(op1+1,op2);
        }else{
            int op1=func(a,n-1,sum,dp);
            if(op1==INT_MIN)
            {
                return dp[n][sum]=INT_MIN;
            }
            return dp[n][sum]=op1;
        }
    }
    int coinChange(vector<int>& a, int sum) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int ans=func(a,n,sum,dp);
        if(ans<0)
        {
            return -1;
        }
        return ans;
    }
};

















