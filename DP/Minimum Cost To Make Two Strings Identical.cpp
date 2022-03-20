
1. You are given two strings S1, S2, and two numbers x and y.
2. The cost of deleting a character from S1 is x and the cost of deleting a character from S2 is y.
3. You can delete characters from both the strings.
4. You have to find the minimum cost required to make the given two strings identical.
Input Format
Two Strings S1, S2
Two numbers x and y
Output Format
A number representing the minimum cost of making the given two strings identical.

#include<bits/stdc++.h>
using namespace std;
int func(string s1,string s2,int n,int m,int &x,int &y,vector<vector<int>> &dp)
{
    if(n==0)
    {
        return (y*m);
    }
    if(m==0)
    {
        return (n*x);
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=func(s1,s2,n-1,m-1,x,y,dp);
    }else{
        return dp[n][m]=min(x+func(s1,s2,n-1,m,x,y,dp),y+func(s1,s2,n,m-1,x,y,dp));
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int x,y;
    cin>>x>>y;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=func(s1,s2,n,m,x,y,dp);
    cout<<ans;
}
