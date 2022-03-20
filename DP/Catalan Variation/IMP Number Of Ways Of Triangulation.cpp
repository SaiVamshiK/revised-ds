
1. You are given a number N, which represents the number of sides in a polygon.
2. You have to find the total number of ways in which the given polygon can be triangulated.
Input Format
A number N
Output Format
A number representing number of ways of traingulating a N-sided polygon.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //************************//
    n=n-2;
    //************************//
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int ways=0;
        for(int j=0;j<i;j++)
        {
            ways+=(((dp[j])*(dp[i-j-1])));
        }
        dp[i]=ways;
    }
    cout<<dp[n];
}
