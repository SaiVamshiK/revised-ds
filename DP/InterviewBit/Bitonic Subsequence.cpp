
Given an 1D integer array A of length N, 
find the length of longest subsequence which is first increasing then decreasing.

int Solution::longestSubsequenceLength(const vector<int> &a) {
    int n=a.size();
    if(n==0||(n==1))
    {
        return n;
    }
    int *lis=new int[n];
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    int *lds=new int[n];
    for(int i=0;i<n;i++)
    {
        lds[i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>(a[j]))
            {
                lds[i]=max(lds[i],lds[j]+1);
            }
        }
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,lis[i]+lds[i]-1);
    }
    return ans;
}

