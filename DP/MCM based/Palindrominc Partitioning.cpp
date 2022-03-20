Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Input Format:

The first and the only argument contains the string A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
Constraints:

1 <= length(A) <= 501
Examples:

Input 1:
    A = "aba"

Output 1:
    0

Explanation 1:
    "aba" is already a palindrome, so no cuts are needed.

Input 2:
    A = "aab"
    
Output 2:
    1

bool isPalin(string s)
{
    string rev=s;
    reverse(s.begin(),s.end());
    return rev==s;
}
int func(string &s,int n,int i,int j,int **dp)
{
    if(i==j||(isPalin(s.substr(i,j-i+1))))
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<=(j-1);k++)
    {
        int t1;
        if(dp[i][k]!=-1)
        {
            t1=dp[i][k];
        }else{
            t1=func(s,n,i,k,dp);
        }
        int t2;
        if(dp[k+1][j]!=-1)
        {
            t2=dp[k+1][j];
        }else{
            t2=func(s,n,k+1,j,dp);
        }
        ans=min(ans,t1+t2+1);
    }
    return dp[i][j]=ans;
}
int Solution::minCut(string s) {
    int n=s.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    return func(s,n,0,n-1,dp);
}













