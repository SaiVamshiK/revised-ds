#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll func(ll *a,ll i,ll j,vector<vector<ll>> &dp)
{
	if(i==j)
	{
		return a[i];
	}
	if(i==(j-1))
	{
		return max(a[i],a[j]);
	}
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
	ll op1=a[i]+min(func(a,i+2,j,dp),func(a,i+1,j-1,dp));
	ll op2=a[j]+min(func(a,i+1,j-1,dp),func(a,i,j-2,dp));
	return dp[i][j]=max(op1,op2);
}
int main()
{
	ll n;
	cin>>n;
	ll *a=new ll[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
	ll f1=func(a,0,n-1,dp);
	ll f2=sum-f1;
	cout<<(f1-f2);
}

