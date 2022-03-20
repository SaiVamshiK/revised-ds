
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll func(ll n,ll start,vector<vector<ll>> &dp)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	if(dp[n][start]!=-1)
	{
		return dp[n][start];
	}
	ll ans=0;
	if(start==0)
    {
        ans+=func(n-1,0,dp);
	    ans+=func(n-1,1,dp);
    }
    if(start==1)
    {
        ans+=func(n-1,0,dp);
    }
	return dp[n][start]=ans;
}
int main()
{
	ll t;
	cin>>t;
	vector<vector<ll>> dp(91,vector<ll>(2,-1));
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=func(n,0,dp)+func(n,1,dp);
		cout<<ans<<endl;
	}
}
