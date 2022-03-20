Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
********************************
IMPORTANT
Maximizing the cuts here.

******** SEE THIS APPROACH **********
class Solution
{
    public:
    //Function to find the maximum number of cuts.
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
            int f1=func(a,n,sum-a[n-1],dp);
            int f2=func(a,n-1,sum,dp);
            if(f1!=INT_MIN&&(f2!=INT_MIN))
            {
                return dp[n][sum]=max(1+f1,f2);    
            }else if(f1!=INT_MIN&&(f2==INT_MIN))
            {
                return dp[n][sum]=1+f1;
            }else if(f2!=INT_MIN&&(f1==INT_MIN))
            {
                return dp[n][sum]=f2;
            }
            return dp[n][sum]=INT_MIN;
        }else{
            int f1=func(a,n-1,sum,dp);
            if(f1!=INT_MIN)
            {
                return dp[n][sum]=f1;    
            }
            return dp[n][sum]=INT_MIN;
        }
    }
    int maximizeTheCuts(int sum, int x, int y, int z)
    {
        int n=3;
        int *a=new int[n];
        a[0]=x;
        a[1]=y;
        a[2]=z;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int ans=func(a,n,sum,dp);
        return (ans!=INT_MIN)?ans:0;
    }
};

int func(int a[],int n,int sum,int **dp)
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
        return dp[n][sum]=max(1+func(a,n,sum-a[n-1],dp),func(a,n-1,sum,dp));
    }
    return dp[n][sum]=func(a,n-1,sum,dp);
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    int a[3]={x,y,z};
    int **dp=new int*[4];
    for(int i=0;i<=3;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans=func(a,3,n,dp);
    return (ans>0)?ans:0;
}



