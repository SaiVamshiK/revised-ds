
An integer array is called arithmetic if it consists of at least three elements and if the difference between 
any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n==0||(n==1)||(n==2))
        {
            return 0;
        }
        int *dp=new int[n];
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<n;i++)
        {
            if((a[i]-a[i-1])==(a[i-1]-a[i-2]))
            {
                dp[i]=1;
                dp[i]+=dp[i-1];
            }else{
                dp[i]=0;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=dp[i];
        }
        return sum;
    }
};
