********************
Recursove Sol

const int MOD=1e9+7;
class Solution{

	public:
	int func(int a[],int n,int sum,int **dp)
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
	    if(a[n-1]<=sum)
	    {
	        return dp[n][sum]=((func(a,n-1,sum-a[n-1],dp)%MOD)+(func(a,n-1,sum,dp)%MOD))%MOD;
	    }else{
	        return dp[n][sum]=(func(a,n-1,sum,dp)%MOD);
	    }
	}
	int perfectSum(int a[], int n, int sum)
	{
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
	  
};




*****************************
Table Method



int perfectSum(int a[], int n, int sum)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=((dp[i-1][j]%MOD)+(dp[i-1][j-a[i-1]]%MOD))%MOD;
            }else{
                dp[i][j]=dp[i-1][j]%MOD;
            }
        }
    }
    return dp[n][sum]%MOD;
}
