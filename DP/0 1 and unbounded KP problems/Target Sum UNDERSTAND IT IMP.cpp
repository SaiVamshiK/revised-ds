You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
*************************************
Recusive Solution:
	here we did not consider 0 's' in the recursion whenever 0 is there in the array we just ignored it
	because we only deal with +ve numbers in the subset problem
	so to tackle 0's' we have not considered it in our dp finally in the answer to consider the 0's ' back we need to have the count of zeros
	which we counted initially
	Now we need to add zeros to all the subsets which we have obtained not considering the zeros by multiplying the answer with 2^cnt(as cnt number of 
	zeros can have 2^cnt combinations)


class Solution {
public:
    int func(vector<int>& a,int n,int sum,int **dp)
    {
        if(sum==0)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(a[n-1]==0)
        {
            return dp[n][sum]=func(a,n-1,sum,dp);
        }
        if(a[n-1]<=sum)
        {
            return dp[n][sum]=func(a,n-1,sum,dp)+func(a,n-1,sum-a[n-1],dp);
        }else{
            return dp[n][sum]=func(a,n-1,sum,dp);
        }
    }
    int findTargetSumWays(vector<int>& a, int diff) {
        int sum=0,n=a.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(a[i]==0)
            {
                cnt++;
            }
        }
        if(diff>sum)
        {
            return 0;
        }
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[sum+1];
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=-1;
            }
        }
        if((sum-diff)%2!=0)
        {
            return 0;
        }
        int x=(sum-diff)/2;
        return pow(2,cnt)*func(a,n,x,dp);
    }
};






**************************** SEE THIS APPROACH ********************************


class Solution {
public:
    int func(vector<int> &a,int n,int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return 1;
        }
        if(n==0)
        {
            return INT_MIN;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(a[n-1]<=sum)
        {
            int op1=func(a,n-1,sum-a[n-1],dp),op2=func(a,n-1,sum,dp);
            if(op1!=INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][sum]=op1+op2;
            }else if(op1!=INT_MIN&&(op2==INT_MIN))
            {
                return dp[n][sum]=op1;
            }else if(op1==INT_MIN&&(op2!=INT_MIN))
            {
                return dp[n][sum]=op2;
            }else{
                return dp[n][sum]=INT_MIN;
            }
        }else{
            int op1=func(a,n-1,sum,dp);
            if(op1!=INT_MIN)
            {
                return dp[n][sum]=op1;
            }else{
                return dp[n][sum]=INT_MIN;
            }
        }
    }
    int findTargetSumWays(vector<int>& nums, int diff) {
        vector<int> a;
        int cnt=0,sum=0;
        for(int i=0;i<(nums.size());i++)
        {
            if(nums[i]==0)
            {
                cnt++;
            }else{
                sum+=nums[i];
                a.push_back(nums[i]);
            }
        }
        if(diff>sum)
        {
            return 0;
        }
        int mul=pow(2,cnt);
        int n=a.size();
        if((diff+sum)%2!=0)
        {
            return 0;
        }
        int req=((diff+sum)/2);
        vector<vector<int>> dp(n+1,vector<int>(req+1,-1));
        return mul*func(a,n,req,dp);
    }
};



