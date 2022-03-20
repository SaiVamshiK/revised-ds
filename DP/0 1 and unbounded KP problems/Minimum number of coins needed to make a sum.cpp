You are given coins of different denominations and a total amount of money amount. Write a function to compute the 
fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the 
coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

************************* SEE THIS APPROACH ************************

typedef pair<bool,int> pi;
class Solution{
	public:
	pair<bool,int> func(int a[],int n,int sum,vector<vector<pi>> &dp)
	{
	    if(sum==0)
	    {
	        return {true,0};
	    }
	    if(n==0)
	    {
	        return {false,-1};
	    }
	    if(dp[n][sum].second!=INT_MIN)
	    {
	        return dp[n][sum];
	    }
	    if(a[n-1]<=sum)
	    {
	        pair<bool,int> op1=func(a,n,sum-a[n-1],dp);
	        pair<bool,int> op2=func(a,n-1,sum,dp);
	        if(op1.first&&(op2.first))
	        {
	            int val=min(op1.second+1,op2.second);
	            return dp[n][sum]={true,val};
	        }else if((op1.first)&&(!op2.first))
	        {
	            return dp[n][sum]={true,op1.second+1};
	        }else if((!op1.first)&&(op2.first))
	        {
	            return dp[n][sum]={true,op2.second};
	        }else{
	            return dp[n][sum]={false,-1};
	        }
	    }else{
	        pair<bool,int> op1=func(a,n-1,sum,dp);
	        if(op1.first)
	        {
	            return dp[n][sum]={true,op1.second};
	        }else{
	            return dp[n][sum]={false,-1};
	        }
	    }
	}
	int minCoins(int a[], int n, int sum) 
	{ 
	    vector<vector<pi>> dp(n+1,vector<pi>(sum+1,{false,INT_MIN}));
        pair<bool,int> ans=func(a,n,sum,dp);
        if(ans.first)
        {
            return ans.second;
        }
        return -1;
	} 
	  
};

**************************************
Recursive Solution

class Solution {
public:
    int func(vector<int> &a,int n,int sum,int **dp)
    {
        if(sum==0)
        {
            return 0;
        }
        if(n==0)
        {
            return INT_MAX;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(a[n-1]<=sum)
        {
            int x=func(a,n,sum-a[n-1],dp),y=func(a,n-1,sum,dp);
            if(x==INT_MAX&&(y==INT_MAX))
            {
                return dp[n][sum]=INT_MAX;
            }
            if(x==INT_MAX&&(y!=INT_MAX))
            {
                return dp[n][sum]=y;
            }
            if(x!=INT_MAX&&(y==INT_MAX))
            {
                return dp[n][sum]=x+1;
            }
            if(x!=INT_MAX&&(y!=INT_MAX))
            {
                return dp[n][sum]=min(x+1,y);
            }
        }
        int x=func(a,n-1,sum,dp);
        return dp[n][sum]=x;
    }
    int coinChange(vector<int>& a, int sum) {
        int n=a.size();
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[sum+1];
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans=func(a,n,sum,dp);
        return (ans!=INT_MAX)?ans:-1;
    }
};
