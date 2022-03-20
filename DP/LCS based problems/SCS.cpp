Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.



//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n
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
    if(s1[n-1]==(s2[m-1]))
    {
        return dp[n][m]=1+func(s1,s2,n-1,m-1,dp);
    }else{
        return dp[n][m]=max(func(s1,s2,n,m-1,dp),func(s1,s2,n-1,m,dp));
    }
}
int shortestCommonSupersequence(char* X, char* Y, int n, int m) {
    string s1;
    for(int i=0;i<n;i++)
    {
        s1.push_back(X[i]);
    }
    string s2;
    for(int i=0;i<m;i++)
    {
        s2.push_back(Y[i]);
    }
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    return n+m-func(s1,s2,n,m,dp);
    
}



