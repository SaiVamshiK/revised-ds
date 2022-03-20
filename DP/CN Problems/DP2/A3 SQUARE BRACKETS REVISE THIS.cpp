
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2 

#include <bits/stdc++.h>
using namespace std;
int func(unordered_set<int> &st,int i,int n,int op,int cl,vector<vector<int>> &dp)
{
    if(i==(2*n))
    {
        if(op==cl)
        {
            return 1;
        }
        return INT_MIN;
    }
    if(dp[i][op]!=-1)
    {
        return dp[i][op];
    }
    if(op==cl)
    {
        int op1=func(st,i+1,n,op+1,cl,dp);
        return dp[i][op]=op1;
    }else{
        if(st.find(i)==st.end())
        {
            int op1=func(st,i+1,n,op+1,cl,dp);
            int op2=func(st,i+1,n,op,cl+1,dp);
            if(op1!=INT_MIN&&(op2!=INT_MIN))
            {
                return dp[i][op]=op1+op2;
            }else if(op1!=INT_MIN)
            {
                return dp[i][op]=op1;
            }else if(op2!=INT_MIN)
            {
				return dp[i][op]=op2;
            }else{
                return dp[i][op]=INT_MIN;
            }
        }else{
            int op1=func(st,i+1,n,op+1,cl,dp);
            return dp[i][op]=op1;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        unordered_set<int> st;
        int a;
        for(int i=0;i<k;i++)
        {
            cin>>a;
            a--;
            st.insert(a);
        }
        vector<vector<int>> dp((2*n)+1,vector<int>((2*n),-1));
        int ans=func(st,0,n,0,0,dp);
        if(ans==INT_MIN)
        {
            cout<<0<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
