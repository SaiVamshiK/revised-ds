
You are given a magic grid A with R rows and C columns. 
In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, 
which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you 
can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. 
You have to find the minimum number of strength points with which you will be able to reach the destination cell.

#include<bits/stdc++.h>
using namespace std;
int getMinimumStrength(int** a, int n, int m) {
    vector<vector<int>> dp(n,vector<int>(m));
    dp[n-1][m-1]=0;
    for(int i=m-2;i>=0;i--)
    {
        int val=dp[n-1][i+1]-a[n-1][i+1];
        dp[n-1][i]=max(1,val);
    }
    for(int i=n-2;i>=0;i--)
    {
        int val=dp[i+1][m-1]-a[i+1][m-1];
        dp[i][m-1]=max(1,val);
    }
    for(int i=n-2;i>=0;i--)
    {
		for(int j=m-2;j>=0;j--)
        {
            int val=min(dp[i][j+1]-a[i][j+1],dp[i+1][j]-a[i+1][j]);
            dp[i][j]=((val<=0)?1:val);
        }
    }
    return dp[0][0];
}



int func(int **a,int i,int j,int n,int m,int **dp)
{
    if((i==(n-1))&&(j==(m-1)))
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if((i+1<n)&&(j+1<m))
    {
        int f1=func(a,i+1,j,n,m,dp),f2=func(a,i,j+1,n,m,dp);
        int a1=f1-a[i+1][j],a2=f2-a[i][j+1];
        if(a1<=0)
        {
            a1=1;
        }
        if(a2<=0)
        {
            a2=1;
        }
        return dp[i][j]=min(a1,a2);
    }
    if((i+1<n))
    {
        int f1=func(a,i+1,j,n,m,dp);
        int a1=f1-a[i+1][j];
        if(a1<=0)
        {
            a1=1;
        }
        return dp[i][j]=a1;
    }
    if((j+1<m))
    {
        int f1=func(a,i,j+1,n,m,dp);
        int a1=f1-a[i][j+1];
        if(a1<=0)
        {
            a1=1;
        }
        return dp[i][j]=a1;
    }
}

int getMinimumStrength(int** a, int n, int m) {
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j]=-1;
        }
    }
	return func(a,0,0,n,m,dp);
}





















