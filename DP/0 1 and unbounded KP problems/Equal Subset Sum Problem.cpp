*********************************
Recursion Used
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
class Solution{
public:
    bool func(int a[],int n,int sum,int **dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        if(a[n-1]<=sum)
        {
            return func(a,n-1,sum-a[n-1],dp)||func(a,n-1,sum,dp);
        }
        return func(a,n-1,sum,dp);
    }
    int equalPartition(int n, int a[])
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        if(sum%2==0)
        {
            sum=sum/2;
            int **dp=new int*[n+1];
            for(int i=0;i<=n;i++)
            {
                dp[i]=new int[sum+1];
                for(int j=0;j<=sum;j++)
                {
                    dp[i][j]=-1;
                }
            }
            return func(a,n,sum,dp);
        }
        return 0;
    }
};


*******************
Table method


// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int a[])
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        if(sum%2==0)
        {
            sum=sum/2;
            bool **dp=new bool*[n+1];
            for(int i=0;i<=n;i++)
            {
                dp[i]=new bool[sum+1];
            }
            for(int i=0;i<=n;i++)
            {
                dp[i][0]=true;
            }
            for(int i=1;i<=sum;i++)
            {
                dp[0][i]=false;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    if(a[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j]||(dp[i-1][j-a[i-1]]);
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
        }
        return 0;
    }
};


