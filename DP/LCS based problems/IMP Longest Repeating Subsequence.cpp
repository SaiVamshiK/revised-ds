Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
 

Exampel 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".
class Solution {
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
	        if(s1[n-1]==s2[m-1]&&((n-1)!=(m-1)))
	        {
	            return dp[n][m]=1+func(s1,s2,n-1,m-1,dp);
	        }else{
	            return dp[n][m]=max(func(s1,s2,n-1,m,dp),func(s1,s2,n,m-1,dp));
	        }
	    }
		int LongestRepeatingSubsequence(string s1){
		    int n=s1.size();
		    string s2=s1;
		    int **dp=new int*[n+1];
		    for(int i=0;i<=n;i++)
		    {
		        dp[i]=new int[n+1];
		    }
		    for(int i=0;i<=n;i++)
		    {
		        dp[i][0]=0;
		    }
		    for(int i=0;i<=n;i++)
		    {
		        dp[0][i]=0;
		    }
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=n;j++)
		        {
		            if(s1[i-1]==s2[j-1]&&((i-1)!=(j-1)))
		            {
		                dp[i][j]=1+dp[i-1][j-1];
		            }else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}
};




