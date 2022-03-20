
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. 
In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character

#include<bits/stdc++.h>
using namespace std;
int func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(n==0)
    {
        return m;
    }
    if(m==0)
    {
        return n;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]!=s2[m-1])
    {
        int op1=func(s1,s2,n-1,m-1,dp);
        int op2=func(s1,s2,n,m-1,dp);
        int op3=func(s1,s2,n-1,m,dp);
        return dp[n][m]=min(op1,min(op2,op3))+1;
    }else{
        int op1=func(s1,s2,n-1,m-1,dp);
        return dp[n][m]=op1;
    }
}
int editDistance(string s1, string s2)
{
	int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return func(s1,s2,n,m,dp);
}


int func(string s1,string s2,int n,int m,int **dp)
{
    if(n==0)
    {
		return m;
    }
    if(m==0)
    {
        return n;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=func(s1,s2,n-1,m-1,dp);
    }else{
        return dp[n][m]=min(1+func(s1,s2,n-1,m-1,dp),min(1+func(s1,s2,n,m-1,dp),1+func(s1,s2,n-1,m,dp)));
    }
    
}
int editDistance(string s1, string s2)
{
    int n=s1.size(),m=s2.size();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
	return func(s1,s2,n,m,dp);
}









