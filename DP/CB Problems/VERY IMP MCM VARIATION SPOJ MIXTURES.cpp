
Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
You can find the original problem here.

Input Format
The first line of each input file will contain n, the number of mixtures. The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Constraints
1 <= n <= 100

Output Format
Output the minimum amount of smoke.

Sample Input
3
40 60 20
Sample Output
2400
Explanation
There are two possibilities: first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400. first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400. The first scenario is a much better way to proceed.

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
pi func(int *a,int i,int j,vector<vector<pi>> &dp)
{
	if(i==j)
	{
		return {a[i],0};
	}
	if(dp[i][j].first!=-1&&(dp[i][j].second!=-1))
	{
		return dp[i][j];
	}
	pi ans={0,INT_MAX};
	for(int k=i;k<=(j-1);k++)
	{
		pi f1=func(a,i,k,dp),f2=func(a,k+1,j,dp);
		int l1=f1.first,s1=f1.second,l2=f2.first,s2=f2.second;
		int result_smoke=(l1*l2)+s1+s2;
		if(ans.second>(result_smoke))
		{
			ans={(l1+l2)%100,result_smoke};
		}
	}
	return dp[i][j]=ans;
}
int main() {
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<vector<pi>> dp(n+1,vector<pi>(n+1,{-1,-1}));
	cout<<func(a,0,n-1,dp).second;
	
	return 0;
}
