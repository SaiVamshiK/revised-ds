************
Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

 

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.
******************
Recursive Solution



class Solution{
public:
    int func(int wt[],int val[],int n,int W,int **dp)
    {
        if(W==0||(n==0))
        {
            return 0;
        }
        if(dp[n][W]!=-1)
        {
            return dp[n][W];
        }
        if(wt[n-1]<=W)
        {
            return dp[n][W]=max(func(wt,val,n,W-wt[n-1],dp)+val[n-1],func(wt,val,n-1,W,dp));
        }else{
            return dp[n][W]=func(wt,val,n-1,W,dp);
        }
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[W+1];
            for(int j=0;j<=W;j++)
            {
                dp[i][j]=-1;
            }
        }
        return func(wt,val,n,W,dp);
    }
};
