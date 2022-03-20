Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        int *dp=new int[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            int ans=0;
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                {
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]+=ans;
        }
        int f=-1;
        for(int i=0;i<n;i++)
        {
            f=max(f,dp[i]);
        }
        return f;
    }
};
