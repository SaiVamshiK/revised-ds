
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, 
and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int func(int f,int n,vector<vector<int>> &dp)
    {
        if(f==0||(f==1))
        {
            return 1;
        }
        if(n==1)
        {
            return f;
        }
        if(dp[f][n]!=-1)
        {
            return dp[f][n];
        }
        int temp=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int op1=func(k-1,n-1,dp);
            int op2=func(f-k,n,dp);
            temp=min(temp,1+max(op1,op2));
        }
        return dp[f][n]=temp;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return func(k,n,dp);
    }
};

