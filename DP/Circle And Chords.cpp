
1. You are given a number N.
2. There are 2*N points on a circle. You have to draw N non-intersecting chords on a circle.
3. You have to find the number of ways in which these chords can be drawn.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll *dp=new ll[n+1];
    dp[0]=1;
    dp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        ll ways=0;
        for(ll j=0;j<i;j++)
        {
            ways+=(dp[j]*dp[i-j-1]);
        }
        dp[i]=ways;
    }
    cout<<dp[n]<<endl;
}
