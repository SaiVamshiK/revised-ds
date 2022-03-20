bool func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(n==0)
    {
        if(m==0)
        {
            return true;
        }
        for(int i=0;i<m;i++)
        {
            if(s2[i]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(m==0)
    {
        return false;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        bool op1=func(s1,s2,n-1,m-1,dp);
        return dp[n][m]=op1;
    }else{
        if(s2[m-1]=='*')
        {
            bool op1,op2,op3;
            if(dp[n][m-1]!=-1)
            {
                op1=dp[n][m-1];
            }else{
                op1=func(s1,s2,n,m-1,dp);
                dp[n][m-1]=op1;
            }
            if(dp[n-1][m-1]!=-1)
            {
                op2=dp[n-1][m-1];
            }else{
                op2=func(s1,s2,n-1,m-1,dp);
                dp[n-1][m-1]=op2;
            }
            if(dp[n-1][m]!=-1)
            {
                op3=dp[n-1][m];
            }else{
                op3=func(s1,s2,n-1,m,dp);
                dp[n-1][m]=op3;
            }
            return dp[n][m]=op1||(op2)||(op3);
        }else if(s2[m-1]=='?')
        {
            bool op;
            if(dp[n-1][m-1]!=-1)
            {
                op=dp[n-1][m-1];
            }else{
                op=func(s1,s2,n-1,m-1,dp);
                dp[n-1][m-1]=op;
            }
            return dp[n][m]=op;
        }else{
            return dp[n][m]=false;
        }
    }
}
int Solution::isMatch(const string s1, const string s2) {
    int n=s1.size(),m=s2.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return func(s1,s2,n,m,dp);
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
    }
    dp[0][0]=true;
    for(int i=1;i<=m;i++)
    {
        bool done=false;
        for(int j=0;j<i;j++)
        {
            if(s2[j]!='*')
            {
                done=true;
                dp[0][i]=false;
                break;
            }
        }
        if(!done)
        {
            dp[0][i]=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }else{
                if(s2[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||(dp[i-1][j-1])||(dp[i][j-1]);
                }else if(s2[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=false;
                }
            }
        }
    }
    return dp[n][m];
}

