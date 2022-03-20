const int MOD=1e9+7;
int func(string s,int n,bool &done,int *dp)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        if(s[0]=='0')
        {
            done=true;
            return 0;
        }
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int last=s[n-1]-'0';
    if(last==0)
    {
        int last_sec=s[n-2]-'0';
        int val=(last_sec*10)+last;
        if(val>=1&&(val<=26))
        {
            return dp[n]=(func(s,n-2,done,dp)%MOD);
        }else{
            done=true;
            return dp[n]=0;
        }
    }else{
        int last_sec=s[n-2]-'0';
        int ans1=func(s,n-1,done,dp);
        if(last_sec==0)
        {
            return dp[n]=ans1%MOD;
        }
        int val=(last_sec*10)+last;
        if(val>=1&&(val<=26))
        {
            ans1=((ans1%MOD)+(func(s,n-2,done,dp)%MOD))%MOD;
        }
        return dp[n]=ans1%MOD;
    }
}
int Solution::numDecodings(string s) {
    int n=s.size();
    bool done=false;
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    int ans=func(s,n,done,dp);
    if(done)
    {
        return 0;
    }
    return ans;
}

