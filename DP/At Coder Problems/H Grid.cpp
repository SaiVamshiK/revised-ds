#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main()
{
	char ch;
	int n,m;
	cin>>n>>m;
	int **a=new int*[n];
	int **dp=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		dp[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			cin>>ch;
			if(ch=='.')
			{
				a[i][j]=0;
			}else{
				a[i][j]=1;
			}
		}
	}
	dp[n-1][m-1]=1;
	for(int i=m-2;i>=0;i--)
	{
		if(a[n-1][i]==0)
		{
			dp[n-1][i]=1;
		}else{
			for(int x=i;x>=0;x--)
			{
				dp[n-1][x]=0;
			}
			break;
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		if(a[i][m-1]==0)
		{
			dp[i][m-1]=1;
		}else{
			for(int x=i;x>=0;x--)
			{
				dp[x][m-1]=0;
			}
			break;
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			if(a[i][j]==0)
			{
				dp[i][j]=((dp[i][j+1]%MOD)+(dp[i+1][j]%MOD))%MOD;
			}else{
				dp[i][j]=0;
			}
		}
	}
	cout<<dp[0][0];
}






















