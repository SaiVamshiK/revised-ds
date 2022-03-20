#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> dp(n+1,INT_MAX);
	dp[0]=0;
	dp[1]=0;
	dp[2]=abs(a[1]-a[0]);
	for(int i=3;i<=n;i++)
	{
		int temp=k;
		for(int j=i-1;j>0&&(temp>0);j--,temp--)	
		{
			dp[i]=min(dp[i],dp[j]+abs(a[i-1]-a[j-1]));
		}
	}
	cout<<dp[n];
}
