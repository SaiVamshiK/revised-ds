
1. You are given a number N representing number of elements.
2. You are given N space separated numbers (ELE : elements).
3. Your task is to find & print  
    3.1) "MINIMUM JUMPS" need from 0th step to (n-1)th step.
    3.2) all configurations of "MINIMUM JUMPS".
NOTE: Checkout sample question/solution video inorder to have more insight.
Input Format
A number N (representing "NUMBER OF ELEMENTS").
ELE1 ,ELE2 ,ELE3 ,ELE4 .... ELEn (N space separated numbers represnting numbers).
Output Format
1) A number representing "MINIMUM JUMPS" need from 0th step to (n-1)th step.
2) Strings representing configurations of "MINIMUM JUMPS".

#include<bits/stdc++.h>
using namespace std;
void func(int *a,int *dp,int i,int n,vector<int> &op,vector<vector<int>> &ans)
{
	if(i==(n-1))
	{
		ans.push_back(op);
		return ;
	}
	int maxSteps=a[i];
	int curLength=dp[i];
	curLength--;
	for(int j=1;j<=(maxSteps)&&(j<n);j++)
	{
		int idx=i+j;
		if((idx<n)&&(dp[idx]==(curLength)))
		{
			op.push_back(idx);
			func(a,dp,idx,n,op,ans);
			op.pop_back();
		}
	}
}
void printPaths(int *dp,int *a,int n)
{
	// i=0 to n-1
	vector<int> op;
	vector<vector<int>> ans;
	op.push_back(0);
	func(a,dp,0,n,op,ans);
	for(int i=0;i<(ans.size());i++)
	{
		int len=ans[i].size();
		for(int j=0;j<len;j++)
		{
			if(j==(len-1))
			{
				cout<<ans[i][j]<<" ."<<endl;
			}else{
				cout<<ans[i][j]<<" -> ";	
			}
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
	int *dp=new int[n];
	dp[n-1]=0;
	for(int i=n-2;i>=0;i--)
	{
		int maxSteps=a[i];
		int minJumps=INT_MAX;
		for(int j=1;j<=maxSteps&&(j<n);j++)
		{
            int idx=i+j;
			if((idx<n)&&(idx==(n-1)||(dp[idx]!=0)))
			{
				minJumps=min(minJumps,dp[idx]+1);	
			}
		}
		if(minJumps!=INT_MAX)
		{
			dp[i]=minJumps;
		}else{
			dp[i]=0;
		}
	}
	cout<<dp[0]<<endl;
	printPaths(dp,a,n);
}












