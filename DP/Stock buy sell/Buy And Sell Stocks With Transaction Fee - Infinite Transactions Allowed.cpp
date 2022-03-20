
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are give a number fee, representing the transaction fee for every transaction.
4. You are required to print the maximum profit you can make if you are allowed infinite transactions, but has to pay "fee" for every closed transaction.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
Input Format
A number n
.. n more elements
A number fee
Output Format
A number representing the maximum profit you can make if you are allowed infinite transactions with transaction fee.

#include<bits/stdc++.h>
using namespace std;
int func(int *a,int i,int n,bool started,int &fee,vector<vector<int>> &dp)
{
	if(i==n)
	{
		if(!started)
		{
			return 0;
		}
		return INT_MIN;
	}
	if(dp[i][started]!=-1)
	{
		return dp[i][started];
	}
	if(started)
	{
		int op1=func(a,i+1,n,started,fee,dp);
		int op2=func(a,i+1,n,false,fee,dp);
		if(op1!=INT_MIN&&(op2!=INT_MIN))
		{
			return dp[i][started]=max(op1,op2+a[i]-fee);	
		}else if(op1!=INT_MIN)
		{
			return dp[i][started]=op1;
		}else if(op2!=INT_MIN)
		{
			return dp[i][started]=op2+a[i]-fee;
		}else{
			return dp[i][started]=INT_MIN;
		}
		
	}else{
		int op1=func(a,i+1,n,started,fee,dp);
		int op2=func(a,i+1,n,true,fee,dp);
		if(op1!=INT_MIN&&(op2!=INT_MIN))
		{
			return dp[i][started]=max(op1,op2-a[i]);	
		}else if(op1!=INT_MIN){
			return dp[i][started]=op1;
		}else if(op2!=INT_MIN)
		{
			return dp[i][started]=op2-a[i];
		}else{
			return dp[i][started]=INT_MIN;
		}
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
	int fee;
	cin>>fee;
	vector<vector<int>> dp(n+1,vector<int>(2,-1));
	int ans=func(a,0,n,false,fee,dp);
	cout<<ans;
}

