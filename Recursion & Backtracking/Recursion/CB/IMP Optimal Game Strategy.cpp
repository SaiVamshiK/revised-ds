
Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4
Sample Output
6
Explanation
Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.

#include<bits/stdc++.h>
using namespace std;
int func(int *a,int i,int j)
{
	if(i==j-1)
	{
		return max(a[i],a[j]);
	}
	int op1=a[i]+min(func(a,i+2,j),func(a,i+1,j-1));
	int op2=a[j]+min(func(a,i+1,j-1),func(a,i,j-2));
	return max(op1,op2);
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
	int ans=func(a,0,n-1);
	cout<<ans;
}

**********************************************************
DP SOLUTION
**********************************************************

#include<bits/stdc++.h>
using namespace std;
int func(int *a,int i,int j,vector<vector<int>> &dp)
{
	if(i==j-1)
	{
		return max(a[i],a[j]);
	}
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
	int op1=a[i]+min(func(a,i+2,j,dp),func(a,i+1,j-1,dp));
	int op2=a[j]+min(func(a,i+1,j-1,dp),func(a,i,j-2,dp));
	return dp[i][j]=max(op1,op2);
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
    vector<vector<int>> dp(n,vector<int>(n,-1));
	int ans=func(a,0,n-1,dp);
	cout<<ans;
}
