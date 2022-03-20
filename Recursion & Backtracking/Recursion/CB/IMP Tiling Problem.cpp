Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
ll func(ll n,ll m,vector<ll> &dp)
{
	if(n<0)
	{
		return 0;
	}
	if(n==1||(n==0))
	{
		return 1;
	}
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=0;
    if((n-1)>=0)
    {
        ans+=func(n-1,m,dp);
        ans%=MOD;
    }
    if((n-m)>=0)
    {
        ans+=func(n-m,m,dp);
        ans%=MOD;
    }
    return dp[n]=ans%MOD;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
        vector<ll> dp(n+1,-1);
		cout<<func(n,m,dp)<<endl;
	}
}
