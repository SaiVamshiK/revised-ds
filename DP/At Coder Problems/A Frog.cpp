


#include<bits/stdc++.h>
using namespace std;
int func(int *a,int i,int n,vector<int> &dp)
{
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	if((i+2<n))
	{
		int op1=func(a,i+1,n,dp)+abs(a[i+1]-a[i]);
		int op2=func(a,i+2,n,dp)+abs(a[i+2]-a[i]);
		return dp[i]=min(op1,op2);	
	}
	if((i+1<n))
	{
		int op1=func(a,i+1,n,dp)+abs(a[i+1]-a[i]);
		return dp[i]=op1;
	}
	return dp[i]=0;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> dp(n+1,-1);
	int ans=func(a,0,n,dp);
	cout<<ans;
}	
