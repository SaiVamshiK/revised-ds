Given an NxM matrix that contains only 0s and 1s, 
find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4

int findMaxSquareWithAllZeros(int **a, int n, int m)
{
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=m-1;i>=0;i--)
    {
        if(a[n-1][i]==0)
        {
            dp[n-1][i]=1;
        }else{
			dp[n-1][i]=0;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i][m-1]==0)
        {
            dp[i][m-1]=1;
        }else{
            dp[i][m-1]=0;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            if(a[i][j]==0)
            {
				int val=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
            	dp[i][j]=1+val;
            }else{
                dp[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}


int findMaxSquareWithAllZeros(int **a, int n, int m)
{
	int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
        }
    }
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(a[i][j]==0)
            {
                int a1=0,a2=0,a3=0;
                if((i+1<n))
                {
                    a1=dp[i+1][j];
                }
                if((j+1<m))
                {
                    a2=dp[i][j+1];
                }
                if((i+1<n)&&(j+1<m))
                {
                    a3=dp[i+1][j+1];
                }
                dp[i][j]=1+min(a1,min(a2,a3));
                ans=max(ans,dp[i][j]);
            }
        }
    }
    return ans;
}

















