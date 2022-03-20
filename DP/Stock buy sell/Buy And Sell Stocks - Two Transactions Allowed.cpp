
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
Output Format
A number representing the maximum profit you can make if you are allowed a single transaction.

#include<bits/stdc++.h>
using namespace std;
int func(int *a,int i,int n,int k,bool started,vector<vector<vector<int>>> &dp)
{
	if(k==0)
	{
		return 0;
	}
	if(i==n)
	{
		if(!started)
		{
			return 0;
		}
		return INT_MIN;
	}
	if(dp[i][k][started]!=-1)
	{
		return dp[i][k][started];
	}
	if(started)
	{
		int op1=func(a,i+1,n,k,true,dp);
		int op2=func(a,i+1,n,k-1,false,dp);
		if(op1!=INT_MIN&&(op2!=INT_MIN))
		{
			return dp[i][k][started]=max(op1,op2+a[i]);
		}else if(op1!=INT_MIN)
		{
			return dp[i][k][started]=op1;
		}else if(op2!=INT_MIN)
		{
			return dp[i][k][started]=op2+a[i];
		}
		return dp[i][k][started]=INT_MIN;
	}else{
		int op1=func(a,i+1,n,k,false,dp);
		int op2=func(a,i+1,n,k,true,dp);
		if(op1!=INT_MIN&&(op2!=INT_MIN))
		{
			return dp[i][k][started]=max(op1,op2-a[i]);
		}else if(op1!=INT_MIN)
		{
			return dp[i][k][started]=op1;
		}else if(op2!=INT_MIN)
		{
			return dp[i][k][started]=op2-a[i];
		}
		return dp[i][k][started]=INT_MIN;
	}
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
	int k=2;
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
	int ans=func(a,0,n,k,false,dp);
	cout<<ans;
}









