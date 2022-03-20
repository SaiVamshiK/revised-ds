
Print the probability of having more heads than tails. The output is considered correct when the absolute error is not greater than 
10^9

#include<bits/stdc++.h>
using namespace std;
typedef double ll;
ll func(ll *p,ll *q,int n,int h,int t,vector<vector<ll>> &dp)
{
	if(n==0)
	{
		if(h>t)
		{
			return 1;
		}
		return 0;
	}
	if(dp[n][h]>-0.9)
	{
		return dp[n][h];
	}
	ll op1=func(p,q,n-1,h+1,t,dp)*p[n-1];
	ll op2=func(p,q,n-1,h,t+1,dp)*q[n-1];
	return dp[n][h]=op1+op2;
}
int main()
{
	int n;
	cin>>n;
	ll *p=new ll[n];
	ll *q=new ll[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		q[i]=1-p[i];
	}
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
	ll ans=func(p,q,n,0,0,dp);
	cout<<setprecision(9)<<ans;
}
