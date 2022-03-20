

int func(string s,string t,int n,int m,int **dp)
{
    if(n==0||(m==0))
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
	if(s[n-1]==t[m-1])
    {
        return dp[n][m]=1+func(s,t,n-1,m-1,dp);
    }
    return dp[n][m]=max(func(s,t,n,m-1,dp),func(s,t,n-1,m,dp));
}
int lcs(string s, string t)
{
	int n=s.size(),m=t.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    return func(s,t,n,m,dp);
}
