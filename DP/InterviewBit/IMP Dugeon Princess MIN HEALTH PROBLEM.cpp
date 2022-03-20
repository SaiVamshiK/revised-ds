The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.

Dungeon Princess: Example 1



Input arguments to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight’s minimum initial health required.



 Note:
The knight’s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.


int func(vector<vector<int> > &a,int n,int m,int i,int j,vector<vector<int>> &dp)
{
    if(i==(n-1)&&(j==(m-1)))
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if((j+1<m)&&(i+1<n))
    {
        int f1=func(a,n,m,i,j+1,dp);
        int f2=func(a,n,m,i+1,j,dp);
        int ret=min(f1-a[i][j+1],f2-a[i+1][j]);
        if(ret<1)
        {
            ret=1;
        }
        return dp[i][j]=ret;    
    }
    if((j+1<m))
    {
        int f1=func(a,n,m,i,j+1,dp);
        int ret=f1-a[i][j+1];
        if(ret<1)
        {
            ret=1;
        }
        return dp[i][j]=ret;
    }
    if((i+1<n))
    {
        int f2=func(a,n,m,i+1,j,dp);
        int ret=f2-a[i+1][j];
        if(ret<1)
        {
            ret=1;
        }
        return dp[i][j]=ret;
    }
    
}
int Solution::calculateMinimumHP(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=func(a,n,m,0,0,dp)-a[0][0];
    if(ans<1)
    {
        return 1;
    }
    return ans;
}

