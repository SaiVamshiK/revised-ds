Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0

class Solution {
public:
    int func(vector<int> &a,int n,bool ongoing,int k,vector<vector<vector<int>>> &dp)
    {
        if(n==0)
        {
            if(!ongoing&&(k>=0))
            {
                return 0;
            }
            return INT_MIN;
        }
        if(k==0)
        {
            return 0;
        }
        if(dp[n][ongoing][k]!=-1)
        {
            return dp[n][ongoing][k];
        }
        if(!ongoing)
        {
            int op1=func(a,n-1,ongoing,k,dp);
            int op2=func(a,n-1,true,k,dp);
            if(op1!=INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][ongoing][k]=max(op1,op2-a[n-1]);    
            }
            if(op1!=INT_MIN)
            {
                return dp[n][ongoing][k]=op1;
            }
            if(op2!=INT_MIN)
            {
                return dp[n][ongoing][k]=op2-a[n-1];
            }
            return dp[n][ongoing][k]=INT_MIN;
        }else{
            int op1=func(a,n-1,ongoing,k,dp);
            int op2=func(a,n-1,false,k-1,dp);
            if(op1!=INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][ongoing][k]=max(op1,op2+a[n-1]);   
            }
            if(op1!=INT_MIN)
            {
                return dp[n][ongoing][k]=op1;
            }
            if(op2!=INT_MIN)
            {
                return dp[n][ongoing][k]=op2+a[n-1];
            }
            return dp[n][ongoing][k]=INT_MIN;
        }
    }
    int maxProfit(vector<int>& A) {
        vector<int> a;
        for(int i=0;i<(A.size());i++)
        {
            a.push_back(A[i]);
        }
        reverse(a.begin(),a.end());
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=func(a,n,false,2,dp);
        if(ans<0)
        {
            return 0;
        }
        return ans;
    }
};
