Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The efficient way is the one that involves the least number of multiplications. 
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) 
where the ith matrix has the dimensions (arr[i-1] x arr[i]).
class Solution{
public:
    int func(int a[],int n,int i,int j,int **dp)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int t1=func(a,n,i,k,dp);
            int t2=func(a,n,k+1,j,dp);
            ans=min(ans,t1+t2+(a[i-1]*a[k]*a[j]));
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int n, int a[])
    {
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        return func(a,n,1,n-1,dp);
    }
};
