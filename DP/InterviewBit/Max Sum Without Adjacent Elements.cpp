
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.

Input Format:

The first and the only argument of input contains a 2d matrix, A.
Output Format:

Return an integer, representing the maximum possible sum.
Constraints:

1 <= N <= 20000
1 <= A[i] <= 2000
Example:

Input 1:
    A = [   [1]
            [2]    ]

Output 1:
    2

Explanation 1:
    We will choose 2.

Input 2:
    A = [   [1, 2, 3, 4]
            [2, 3, 4, 5]    ]
    
Output 2:
    We will choose 3 and 5.
int func(vector<vector<int> > &a,int n,int *dp)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return max(a[0][0],a[1][0]);
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int op1=a[0][n-1]+func(a,n-2,dp);
    int op2=a[1][n-1]+func(a,n-2,dp);
    int ans1=max(op1,op2);
    int ans2=func(a,n-1,dp);
    return dp[n]=max(ans1,ans2);
}
int Solution::adjacent(vector<vector<int> > &a) {
    int n=a[0].size();
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    return func(a,n,dp);
}

