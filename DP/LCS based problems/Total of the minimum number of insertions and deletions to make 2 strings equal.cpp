Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.


class Solution{
		

	public:
	int func(string s1,string s2,int n,int m,int **dp)
	{
	    if(n==0||(m==0))
	    {
	        return 0;
	    }
	    if(dp[n][m]!=-1)
	    {
	        return dp[n][m];
	    }
	    if(s1[n-1]==s2[m-1])
	    {
	        return dp[n][m]=1+func(s1,s2,n-1,m-1,dp);
	    }else{
	        return dp[n][m]=max(func(s1,s2,n,m-1,dp),func(s1,s2,n-1,m,dp));
	    }
	}
	int minOperations(string s1, string s2) 
	{ 
	    int n=s1.size(),m=s2.size();
	    int **dp=new int*[n+1];
	    for(int i=0;i<=n;i++)
	    {
	        dp[i]=new int[m+1];
	    }
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=0;
	    }
	    for(int i=0;i<=m;i++)
	    {
	        dp[0][i]=0;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(s1[i-1]==s2[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    //int lcs=func(s1,s2,n,m,dp);
	    return (n+m-(2*dp[n][m]));
	} 
};

