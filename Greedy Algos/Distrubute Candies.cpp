
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.

int Solution::candy(vector<int> &a) {
    int n=a.size();
    vector<int> dp(n+1,1);
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            dp[i]=max(dp[i],1+dp[i-1]);
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
        {
            dp[i]=max(dp[i],1+dp[i+1]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(dp[i]);
    }
    return ans;
}

