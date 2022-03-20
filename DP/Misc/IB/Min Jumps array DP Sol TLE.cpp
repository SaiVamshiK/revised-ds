
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

int Solution::jump(vector<int> &a) {
    int n=a.size();
    vector<int> dp(n,0);
    for(int i=n-2;i>=0;i--)
    {
        int val=a[i];
        int idx=i+1;
        int temp=INT_MAX;
        while(val>0&&(idx<n))
        {
            temp=min(temp,dp[idx]);
            idx++;
            val--;
        }
        dp[i]=(temp!=INT_MAX)?(temp+1):INT_MAX;
    }
    return (dp[0]!=INT_MAX)?dp[0]:-1;
}

