
Its Diwali time and everyone is busy decorating there homes using light bulbs. The light bulbs are arranged in a row. Little bob is bored of participating in contests so he decided to write 1 for every bulb which is on and 0 for every bulb which is off and creates an array of size equal to number of light bulbs. Since he is a bright kid he looks at his array and calculates the sum of all the adjacent pairwise products and wonders how many such combinations exist. More formally you are given an array of size n (consisting of 0 and 1 only) and k = a1a2 + a2a3 + a3a4 + … an-1an. You have to find out how many combinations of these light bulbs of size n (on and off) will give the sum of products equal to given value k. You have to calculate this value modulo 10^6+3.

Input Format
The first line consists of number of test cases. The second line consists of two values n and k.

Constraints
test cases <= 100 n <= 100 k <= 100

Output Format
The number of combinations modulo 10^6+3.

#include<bits/stdc++.h>
using namespace std;
const int MOD=pow(10,6)+3;
int adj(int n,int k,int start,vector<vector<vector<int>>> &dp)
{
	if(n==1)
	{
		if(k==0)
		{
			// only 1 string because we are given that the string has to start with 'start'
			return 1;
		}
		return 0;
	}
	if(k<0)
	{
		return 0;
	}
	if(dp[n][k][start]!=-1)
	{
		return dp[n][k][start];
	}
	if(start==0)
	{
		int op1=adj(n-1,k,0,dp);
		int op2=adj(n-1,k,1,dp);
		return dp[n][k][start]=((op1%MOD)+(op2%MOD))%MOD;
	}else{
		int op1=adj(n-1,k,0,dp);
		int op2=adj(n-1,k-1,1,dp);
		return dp[n][k][start]=((op1%MOD)+(op2%MOD))%MOD;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
		long f1=adj(n,k,0,dp),f2=adj(n,k,1,dp);
		long ans=((f1%MOD)+(f2%MOD))%MOD;
		cout<<ans<<endl;
	}
}
