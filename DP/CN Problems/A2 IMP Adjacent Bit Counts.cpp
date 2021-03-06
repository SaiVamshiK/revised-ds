
For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0
Write a program which takes as input integers n and k and returns the number of bit strings x 
of n bits (out of 2n) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways 
of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011

Input
The first line of input contains a single integer P, (1 = P = 1000), which is the number of data sets that follow. 
Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer 
giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving 
the desired adjacent bit count. The number of bits (n) will not be greater than 100.
Output
For each data set there is one line of output. It contains the data set number followed by a single space, followed by 
the number of n-bit strings with adjacent bit count equal to k. As answer can be very large print your answer 
modulo 10^9+7.

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll adjBC(ll n,ll k,ll start,vector<vector<vector<ll>>> &dp)
{
    if(k<0)
    {
        return 0;
    }
    if(n==0)
    {
        if(k==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[n][k][start]!=-1)
    {
        return dp[n][k][start];
    }
	if(start==0)
    {
        return dp[n][k][start]=((adjBC(n-1,k,0,dp)%mod)+(adjBC(n-1,k,1,dp)%mod))%mod;
    }else{
        return dp[n][k][start]=((adjBC(n-1,k,0,dp)%mod)+(adjBC(n-1,k-1,1,dp)%mod))%mod;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll st,n,k;
        cin>>st>>n>>k;
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(k+1,vector<ll>(2,-1)));
        ll ans=((adjBC(n-1,k,0,dp)%mod)+(adjBC(n-1,k,1,dp)%mod))%mod;
        cout<<st<<' '<<ans<<endl;
    }
    return 0;
}



