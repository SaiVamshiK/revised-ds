Given an array arr[] of integers of size N and a number X, the task is to find the sum of subarray having maximum sum less than or equal to the given value of X.

Example 1:

Input: N = 5, X = 11
arr[] = {1, 2, 3, 4, 5} 
Output:  10
Explanation: Subarray having maximum 
sum is {1, 2, 3, 4}.

class Solution{
    public:
	int findMaxSubarraySum(long long a[], int n, long long k)
	{
        int i=0,j=0;
        int sum=0;
        int ans=INT_MIN;
        while(j<n)
        {
            sum=sum+a[j];
            if(sum<=k)
            {
                ans=max(ans,sum);
                j++;
            }else{
                while(sum>k)
                {
                    sum=sum-a[i];
                    i++;
                }
                if(sum<=k)
                {
                    ans=max(ans,sum);
                }
                j++;
            }
        }
        return ans;
	}
};
	  
