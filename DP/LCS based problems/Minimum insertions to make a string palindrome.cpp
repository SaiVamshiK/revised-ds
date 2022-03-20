Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	string s2;
	while(t--)
	{
	    cin>>s2;
	    int m=s2.size();
	    string s1=s2;
	    reverse(s2.begin(),s2.end());
	    int n=s1.size();
	    int **dp=new int*[n+1];
	    for(int i=0;i<=n;i++)
	    {
	        dp[i]=new int[m+1];
	    }
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=0;
	    }
	    for(int i=0;i<=m;i++)
	    {
	        dp[0][i]=0;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(s1[i-1]==s2[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    cout<<(n-dp[n][m])<<endl;
	}
	return 0;
}






