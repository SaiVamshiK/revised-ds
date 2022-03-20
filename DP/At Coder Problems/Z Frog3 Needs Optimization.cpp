#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll func(ll *a,ll i,ll n,ll &c,vector<ll> &dp)
{
	if(i==(n-1))
	{
		return 0;
	}
    if(dp[i]!=-1)
    {
        return dp[i];
    }
	ll cur=i;
	ll ans=-1;
	for(ll j=cur+1;j<n;j++)
	{
		ll f1;
		if(dp[j]!=-1)
		{
			f1=dp[j];
		}else{
			f1=func(a,j,n,c,dp);
			dp[j]=f1;
		}
        ll temp=pow(a[j]-a[cur],2);
        if(ans==-1)
        {
            ans=f1+c+temp;
        }else {
            ans=min(ans,f1+c+temp);
        }
	}
	return dp[i]=ans;
}
int main()
{
	ll n,c;
	cin>>n>>c;
	ll *a=new ll[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
    vector<ll> dp(n+1,-1);
	ll ans=func(a,0,n,c,dp);
	cout<<ans;
}


