Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i,e in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
class Solution {
public:
    void dfs(vector<vector<char>>& vec,int i,int j,int n,int m,bool **visited)
    {
        visited[i][j]=true;
        if((i+1<n)&&(!visited[i+1][j])&&(vec[i+1][j]=='1'))
        {
            dfs(vec,i+1,j,n,m,visited);
        }
        if((j+1<m)&&(!visited[i][j+1])&&(vec[i][j+1]=='1'))
        {
            dfs(vec,i,j+1,n,m,visited);
        }
        if((i-1>=0)&&(!visited[i-1][j])&&(vec[i-1][j]=='1'))
        {
            dfs(vec,i-1,j,n,m,visited);
        }
        if((j-1>=0)&&(!visited[i][j-1])&&(vec[i][j-1]=='1'))
        {
            dfs(vec,i,j-1,n,m,visited);
        }
        if((i+1<n)&&(j+1<m)&&(!visited[i+1][j+1])&&(vec[i+1][j+1]=='1'))
        {
            dfs(vec,i+1,j+1,n,m,visited);
        }
        if((i+1<n)&&(j-1>=0)&&(!visited[i+1][j-1])&&(vec[i+1][j-1]=='1'))
        {
            dfs(vec,i+1,j-1,n,m,visited);
        }
        if((i-1>=0)&&(j-1>=0)&&(!visited[i-1][j-1])&&(vec[i-1][j-1]=='1'))
        {
            dfs(vec,i-1,j-1,n,m,visited);
        }
        if((i-1>=0)&&(j+1<m)&&(!visited[i-1][j+1])&&(vec[i-1][j+1]=='1'))
        {
            dfs(vec,i-1,j+1,n,m,visited);
        }
    }
    int numIslands(vector<vector<char>>& vec) {
        int n=vec.size(),m=vec[0].size();
        bool **visited=new bool*[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new bool[m];
            for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vec[i][j]=='1'&&(!visited[i][j]))
                {
                    ans++;
                    dfs(vec,i,j,n,m,visited);
                }
            }
        }
        return ans;
    }
};
