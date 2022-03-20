You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

int func(string s,int i,int n,int k,vector<vector<int>> &dp)
{
    if(i==n)
    {
        if(k==0)    
        {
            return 0;
        }
        return INT_MAX;
    }
    if(k==0)
    {
        return INT_MAX;
    }
    if(dp[i][k]!=-1)
    {
        return dp[i][k];
    }
    int b=0,w=0;
    int ans=INT_MAX;
    for(int j=i;j<n;j++)
    {
        if(s[j]=='B')
        {
            b++;
        }else{
            w++;
        }
        int temp_ans=func(s,j+1,n,k-1,dp);
        if(temp_ans!=INT_MAX)
        {
           temp_ans+=(b*w);
           ans=min(ans,temp_ans);
        }
    }
    return dp[i][k]=ans;
}
int Solution::arrange(string s, int k) {
    int n=s.size();
    if(k==n)
    {
        return 0;
    }
    if(k>n)
    {
        return -1;
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return func(s,0,n,k,dp);
}

