1. You are given a number n, representing the number of opening brackets ( and closing brackets )
2. You are required to find the number of ways in which you can arrange the brackets if the closing brackets should never exceed opening brackets
e.g.
for 1, answer is 1 -> ()
for 2, answer is 2 -> ()(), (())
for 3, asnwer is 5 -> ()()(), () (()), (())(), (()()), ((()))
Input Format
A number n
Output Format
A number representing the number of ways in which you can arrange the brackets if the closing brackets should never exceed opening brackets

#include<bits/stdc++.h>
using namespace std;
int func(int op,int cl,int n,vector<vector<int>> &dp)
{
	if(dp[op][cl]!=-1)
	{
		return dp[op][cl];
	}
	if(op==cl&&(op==n))
	{
		return dp[op][cl]=1;
	}
    if(op==n)
    {
        int op1=func(op,cl+1,n,dp);
        return dp[op][cl]=op1;
    }
	if(op==cl)
	{
		int op1=func(op+1,cl,n,dp);
		return dp[op][cl]=op1;
	}else{
		int op1=func(op+1,cl,n,dp);
		int op2=func(op,cl+1,n,dp);
		return dp[op][cl]=op1+op2;
	}
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	int ans=func(0,0,n,dp);
	cout<<ans;
}
