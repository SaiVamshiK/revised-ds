Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"

int func(string s1,string s2,int n,int m,vector<vector<int>> &dp)
{
    if(n==0)
    {
        if(m==0)
        {
            return 1;
        }
        return 0;
    }
    if(m<0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
        int op1=func(s1,s2,n-1,m-1,dp);
        int op2=func(s1,s2,n-1,m,dp);
        return dp[n][m]=op1+op2;
    }else{
        int op1=func(s1,s2,n-1,m,dp);
        return dp[n][m]=op1;
    }
}
int Solution::numDistinct(string s1, string s2) {
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return func(s1,s2,n,m,dp);
}

