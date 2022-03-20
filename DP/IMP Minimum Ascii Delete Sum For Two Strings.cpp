
1. You are given two strings S1 and S2.
2. You have to make these two strings equal by deleting characters. You can delete characters from any of the two strings.
3. The cost of deleting a character from any string is the ASCII value of that character.
4. You have to find the minimum ASCII sum of deleted characters.
Input Format
Two Strings S1 and S2
Output Format
A number representing the minimum ASCII sum of deleted characters.

#include<bits/stdc++.h>
using namespace std;
int func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(n==0)
    {
        int ans=0;
        for(int i=m-1;i>=0;i--)
        {
            ans+=(int(s2[i]));
        }
        return dp[n][m]=ans;
    }
    if(m==0)
    {
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=(int(s1[i]));
        }
        return dp[n][m]=ans;
    }
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=func(s1,s2,n-1,m-1,dp);
    }else{
        int op1=func(s1,s2,n-1,m,dp)+int(s1[n-1]);
        int op2=func(s1,s2,n,m-1,dp)+int(s2[m-1]);
        return dp[n][m]=min(op1,op2);
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=func(s1,s2,n,m,dp);
    cout<<ans;
}
