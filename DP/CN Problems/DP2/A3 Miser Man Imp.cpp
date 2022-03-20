
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10

*********************************************	SEE THIS APPROACH	*********************************************

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int **a=new int*[n];
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        dp[n-1][i]=a[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
		for(int j=0;j<m;j++)
        {
            dp[i][j]=a[i][j];
            int minVal=INT_MAX;
            // i+1,j
            if((i+1<n))
            {
                minVal=min(minVal,dp[i+1][j]);
            }
            // i+1,j+1
            if((i+1<n)&&(j+1<m))
            {
                minVal=min(minVal,dp[i+1][j+1]);
            }
            // i+1,j-1
            if((i+1<n)&&(j-1>=0))
            {
                minVal=min(minVal,dp[i+1][j-1]);
            }
            dp[i][j]+=minVal;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<m;i++)
    {
        ans=min(ans,dp[0][i]);
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int **a=new int*[n];
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
		dp[n-1][i]=a[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            int x=INT_MAX,y=INT_MAX,z=INT_MAX;
            if((i+1<n)&&(j-1>=0))
            {
                x=dp[i+1][j-1];
            }
            if((i+1<n))
            {
                y=dp[i+1][j];
            }
            if((i+1<n)&&(j+1<m))
            {
                z=dp[i+1][j+1];
            }
            dp[i][j]=a[i][j]+min(x,min(y,z));
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<m;i++)
    {
        ans=min(ans,dp[0][i]);
    }
    cout<<ans;
    return 0;
}



















