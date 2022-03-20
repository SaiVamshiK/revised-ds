Given a string of S as input. Your task is to write a program to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input:
First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains a string S.

Output:
For each test case, print the deletions required to make the string palindrome.

Constraints:
1<=T<=100
1<=length(S)<=10000

Example:
Input:
2
aebcbda
geeksforgeeks
Output:
2
8

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s2;
	    cin>>s2;
	    int n=s2.size();
	    string s1=s2;
	    reverse(s2.begin(),s2.end());
	    int **dp=new int*[n+1];
	    for(int i=0;i<=n;i++)
	    {
	        dp[i]=new int[n+1];
	    }
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=0;
	    }
	    for(int i=0;i<=n;i++)
	    {
	        dp[0][i]=0;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(s1[i-1]==s2[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    cout<<(n-dp[n][n])<<endl;
	}
	return 0;
}



