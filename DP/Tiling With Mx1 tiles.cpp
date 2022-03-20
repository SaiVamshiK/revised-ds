
1. You are given a number n and a number m separated by line-break representing the length and breadth of a m * n floor.
2. You've an infinite supply of m * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.
Input Format
A number n
A number m
Output Format
A number representing the number of ways in which the number of ways floor can be tiled using tiles.

#include<bits/stdc++.h>
using namespace std;
int func(int m,int n,vector<vector<int>> &dp)
{
    if(m==n)
    {
        return 2;
    }
    if(m>n)
    {
        return 1;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    return dp[m][n]=func(m,n-1,dp)+func(m,n-m,dp);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int ans=func(m,n,dp);
    cout<<ans;
}
