
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        int *dp=new int[n];
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]==0)
            {
                dp[i]=INT_MAX;
                continue;
            }
            int len=arr[i];
            int temp=INT_MAX;
            for(int j=i+1;len>0&&(j<n);len--,j++)
            {
                temp=min(temp,dp[j]);
            }
            if(temp==INT_MAX)
            {
                dp[i]=INT_MAX;
            }else{
                dp[i]=1+temp;   
            }
        }
        int ans=dp[0];
        if(ans==INT_MAX)
        {
            return -1;
        }
        return dp[0];
    }
};
