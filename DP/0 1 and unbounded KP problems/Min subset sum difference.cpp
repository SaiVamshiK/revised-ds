Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the 
absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

*************************************
Recursive Solution

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
	    if(dp[n][sum]!=-1)
	    {
	        return dp[n][sum];
	    }
	    if(a[n-1]<=sum)
	    {
	        return dp[n][sum]=func(a,n-1,sum-a[n-1],dp)||func(a,n-1,sum,dp);
	    }else{
	        return dp[n][sum]=func(a,n-1,sum,dp);
	    }
	}
	int minDiffernce(int a[], int n) 
	{
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
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
        func(a,n,sum,dp);
        if(sum%2==0)
        {
            int x=sum/2;
            if(func(a,n,x,dp))
            {
                return 0;
            }else{
                for(int i=x+1;i<=sum;i++)
                {
                    if(func(a,n,i,dp))
                    {
                        return (2*i-(sum));
                    }
                }
            }
        }else{
            int x=sum/2;
            if(func(a,n,x,dp))
            {
                return 1;
            }
            else{
                for(int i=x+1;i<=sum;i++)
                {
                    if(func(a,n,i,dp))
                    {
                        return (2*i-sum);
                    }
                }
            }
        }
	} 
