bool isPalin(string s)
{
    string temp=s;
    reverse(temp.begin(),temp.end());
    return temp==s;
}
int func(string s,int i,int j,vector<vector<int>> &dp)
{
    if(isPalin(s.substr(i,j-i+1))||(i==j))
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
        int f1,f2;
        if(dp[i][k]!=-1)
        {
            f1=dp[i][k];
        }else{
            f1=func(s,i,k,dp);
            dp[i][k]=f1;
        }
        if(dp[k+1][j]!=-1)
        {
            f2=dp[k+1][j];
        }else{
            f2=func(s,k+1,j,dp);
            dp[k+1][j]=f2;
        }
        int temp=1+f1+f2;
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}

int Solution::minCut(string s) {
    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return func(s,0,n-1,dp);
}













