int Solution::lis(const vector<int> &a) {
    int n=a.size();
    int *dp=new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}

