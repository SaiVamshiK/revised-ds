
Given an integer N denoting the Length of a line segment. 
You need to cut the line segment in such a way that the cut length of a line segment each 
time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

//Complete this function
int func(int *a,int n,int sum,vector<vector<int>> &dp)
{
    if(sum==0)
    {
        return 0;
    }
    if(n==0)
    {
        return INT_MIN;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(a[n-1]<=sum)
    {
        int op1=func(a,n,sum-a[n-1],dp);
        int op2=func(a,n-1,sum,dp);
        if(op1!=INT_MIN&&(op2==INT_MIN))
        {
            return dp[n][sum]=1+op1;
        }
        if(op1==INT_MIN&&(op2!=INT_MIN))
        {
            return dp[n][sum]=op2;
        }
        if(op1==INT_MIN&&(op2==INT_MIN))
        {
            return dp[n][sum]=INT_MIN;
        }
        return dp[n][sum]=max(1+op1,op2);
    }else{
        int op1=func(a,n-1,sum,dp);
        if(op1==INT_MIN)
        {
            return dp[n][sum]=INT_MIN;
        }
        return dp[n][sum]=op1;
    }
}
int maximizeTheCuts(int sum, int x, int y, int z)
{
    int *a=new int[3];
    a[0]=x;a[1]=y;a[2]=z;
    int n=3;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    int ans=func(a,n,sum,dp);
    if(ans<0)
    {
        return 0;
    }
    return ans;
}



