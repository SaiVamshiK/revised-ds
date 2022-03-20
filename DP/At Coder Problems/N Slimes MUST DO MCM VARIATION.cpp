#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
// {smoke_min,total_ltrs}
pi func(ll *a,ll i,ll j,vector<vector<pi>> &dp)
{
	if(i==j)
	{
		return {0,a[i]};
	}
	if(dp[i][j].first!=-1&&(dp[i][j].second!=-1))
	{
		return dp[i][j];
	}
	pi ans={-1,0};
	for(ll k=i;k<(j);k++)
	{
		pi f1=func(a,i,k,dp);
		pi f2=func(a,k+1,j,dp);
		ll x=f1.first+f2.first+(f1.second+f2.second);
		ll y=(f1.second+f2.second);
		if((ans.first==-1)||ans.first>(x))
		{
			ans={x,y};
		}
	}
	return dp[i][j]=ans;
	
}
int main()
{
	ll n;
	cin>>n;
	ll *a=new ll[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<vector<pi>> dp(n+1,vector<pi>(n+1,{-1,-1}));
	pi ans=func(a,0,n-1,dp);
	cout<<ans.first;
}
