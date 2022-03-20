
Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

Two ways are different if there exists a chord which is present in one way and not in other.

Return the answer modulo 109 + 7.



Input Format:

The first and the only argument contains the integer A.
Output Format:

Return an integer answering the query as described in the problem statement.

typedef long long ll;
const int mod=1e9+7;
int Solution::chordCnt(int n) {
    ll *dp=new ll[n+1];
    dp[0]=1;
    dp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        ll ways=0;
        for(ll j=0;j<i;j++)
        {
            ways+=(((dp[j]%mod)*(dp[i-j-1]%mod))%mod);
            ways=(ways+mod)%mod;
        }
        dp[i]=ways;
    }
    return dp[n];
}

