
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 
0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

class Solution {
public:
    void dfs(vector<vector<int>> &grid,int curAmt,int i,int j,int n,int m,vector<vector<bool>> &visited,int &temp)
    {
        visited[i][j]=true;
        temp=max(temp,curAmt);
        // i,j+1
        if((j+1<m)&&(!visited[i][j+1])&&(grid[i][j+1]!=0))
        {
            dfs(grid,curAmt+grid[i][j+1],i,j+1,n,m,visited,temp);
        }
        // i+1,j
        if((i+1<n)&&(!visited[i+1][j])&&(grid[i+1][j]!=0))
        {
            dfs(grid,curAmt+grid[i+1][j],i+1,j,n,m,visited,temp);
        }
        // i,j-1
        if((j-1>=0)&&(!visited[i][j-1])&&(grid[i][j-1]!=0))
        {
            dfs(grid,curAmt+grid[i][j-1],i,j-1,n,m,visited,temp);
        }
        // i-1,j
        if((i-1>=0)&&(!visited[i-1][j])&&(grid[i-1][j]!=0))
        {
            dfs(grid,curAmt+grid[i-1][j],i-1,j,n,m,visited,temp);
        }
        visited[i][j]=false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    int temp=INT_MIN;
                    dfs(grid,grid[i][j],i,j,n,m,visited,temp);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
