
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Input Format:

The first and the only argument is an array of integer, A.
Output Format:

Return an integer, representing the maximum possible profit.
Constraints:

1 <= len(A) <= 1e5
1 <= A[i] <= 1e7
Example :

Input 1:
    A = [1, 2, 3]

Output 1:
    2

Explanation 1:
    => Buy a stock on day 0.
    => Sell the stock on day 1. (Profit +1)
    => Buy a stock on day 1.
    => Sell the stock on day 2. (Profit +1)
    
    Overall profit = 2

Input 2:
    A = [5, 2, 10]

Output 2:
    8

Explanation 2:
    => Buy a stock on day 1.
    => Sell the stock on on day 2. (Profit +8)
    
    Overall profit = 8

int func(vector<int> &a,int n,bool ongoing,vector<vector<int>> &dp)
{
    if(n==0)
    {
        if(!ongoing)
        {
            return 0;
        }
        return INT_MIN;
    }
    if(dp[n][ongoing]!=-1)
    {
        return dp[n][ongoing];
    }
    if(!ongoing)
    {
        int op1=func(a,n-1,ongoing,dp);
        int op2=func(a,n-1,true,dp);
        if(op1!=INT_MIN&&(op2!=INT_MIN))
        {
            return dp[n][ongoing]=max(op1,op2-a[n-1]);   
        }
        if(op1!=INT_MIN)
        {
            return dp[n][ongoing]=op1;
        }
        if(op2!=INT_MIN)
        {
            return dp[n][ongoing]=op2-a[n-1];
        }
        return dp[n][ongoing]=INT_MIN;
    }else{
        int op1=func(a,n-1,ongoing,dp);
        int op2=func(a,n-1,false,dp);
        if(op1!=INT_MIN&&(op2!=INT_MIN))
        {
            return dp[n][ongoing]=max(op1,op2+a[n-1]);   
        }
        if(op1!=INT_MIN)
        {
            return dp[n][ongoing]=op1;
        }
        if(op2!=INT_MIN)
        {
            return dp[n][ongoing]=op2+a[n-1];
        }
        return dp[n][ongoing]=INT_MIN;
    }
}
int Solution::maxProfit(const vector<int> &A) {
    vector<int> a;
    for(int i=0;i<(A.size());i++)
    {
        a.push_back(A[i]);
    }
    reverse(a.begin(),a.end());
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    int ans=func(a,n,false,dp);
    if(ans<0)
    {
        return 0;
    }
    return ans;
}

