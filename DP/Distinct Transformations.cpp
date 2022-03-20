1. You are given two strings S1 and S2.
2. You have to find the number of unique ways in which you can transform S1 to S2.
3. Transformation can be achieved by removing 0 or more characters from S1, such that the sequence formed by the remaining characters of S1 is identical to S2.
Input Format
Two Strings S1 and S2
Output Format
A number representing the count of distinct transformations.


#include<bits/stdc++.h>
using namespace std;
int countTransformations(string &s1,string &s2,int i,int n,int j,int m,vector<vector<int>> &dp)
{
    if(i==n)
    {
        if(j==m)
        {
            return 1;
        }
        return 0;
    }
    if(j==m)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j])
    {
        int op1=countTransformations(s1,s2,i+1,n,j+1,m,dp);
        int op2=countTransformations(s1,s2,i+1,n,j,m,dp);
        return dp[i][j]=op1+op2;
    }else{
        int op1=countTransformations(s1,s2,i+1,n,j,m,dp);
        return dp[i][j]=op1;
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=countTransformations(s1,s2,0,n,0,m,dp);
    cout<<ans;
}



















