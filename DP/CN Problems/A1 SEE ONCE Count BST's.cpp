
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.

Sample Input 1:
8
Sample Output 1:
1430

typedef long long ll;
const int mod=1e9+7;
int countBST( int findVal)
{
    ll *dp=new ll[findVal+1];
    dp[0]=1;
    dp[1]=1;
    for(ll n=2;n<=findVal;n++)
    {
        dp[n]=0;
        for(ll i=1;i<=n;i++)
        {
			dp[n]+=((dp[i-1]%mod)*(dp[n-i]%mod));
            dp[n]%=mod;
        }
    }
    return dp[findVal];
}

const int MOD=1e9+7;
int countBST( int n)
{
    long *dp=new long[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=5;
    for(int cur=4;cur<=n;cur++)
    {
        dp[cur]=0;
        for(int i=1;i<=cur;i++)
        {
            dp[cur]=((dp[cur]%MOD)+(((dp[i-1]%MOD)*(dp[cur-i]%MOD))%MOD))%MOD;
        }
    }
    return dp[n]%MOD;
}


