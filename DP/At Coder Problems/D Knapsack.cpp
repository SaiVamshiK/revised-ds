#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll knapSack(ll W, ll *wt, ll *val, ll n) 
{ 
    ll **dp=new ll*[n+1];
    for(ll i=0;i<=n;i++)
    {
        dp[i]=new ll[W+1];
        for(ll j=0;j<=W;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(ll i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(ll i=0;i<=W;i++)
    {
        dp[0][i]=0;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
	ll n,sum;
	cin>>n>>sum;
	ll *wt=new ll[n];
	ll *val=new ll[n];
	for(ll i=0;i<n;i++)
	{
		cin>>wt[i]>>val[i];
	}
	ll ans=knapSack(sum,wt,val,n);
	cout<<ans;
}
