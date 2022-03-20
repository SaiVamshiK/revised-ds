#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m=3;
	int **a=new int*[n];
	int **dp=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		dp[i]=new int[m];
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		dp[n-1][i]=a[n-1][i];
	}
	for(int i=n-2;i>=0;i--)
	{
		// {i+1,j+1} {i+1,j-1}
		for(int j=0;j<3;j++)
		{
			if(j==0)
			{
				dp[i][j]=a[i][j]+max(dp[i+1][j+1],dp[i+1][2]);
			}
			else if(j==1)
			{
				dp[i][j]=a[i][j]+max(dp[i+1][j+1],dp[i+1][j-1]);
			}else{
				dp[i][j]=a[i][j]+max(dp[i+1][j-1],dp[i+1][0]);
			}
		}
	}
	int ans=max(dp[0][0],max(dp[0][1],dp[0][2]));
	cout<<ans;
}
