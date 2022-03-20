Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

class Solution {
public:
    bool func(vector<vector<int>> &a,int i,int j,int n,int m,vector<vector<bool>> &visited)
    {
        visited[i][j]=true;
        if((i==(n-1))&&(j==(m-1)))
        {
            return true;
        }
        int cur=a[i][j];
        if(cur==1)
        {
            // i,j-1
            if((j-1>=0)&&(!visited[i][j-1])&&((a[i][j-1]==4)||(a[i][j-1]==6)||(a[i][j-1]==1)))
            {
                bool op1=func(a,i,j-1,n,m,visited);
                if(op1)
                {
                    return true;
                }
            }
            // i,j+1
            if((j+1<m)&&(!visited[i][j+1])&&((a[i][j+1]==3||(a[i][j+1]==5)||(a[i][j+1]==1))))
            {
                bool op2=func(a,i,j+1,n,m,visited);
                if(op2)
                {
                    return true;
                }
            }
        }else if(cur==2)
        {
            // i-1,j
            if((i-1>=0)&&(!visited[i-1][j])&&((a[i-1][j]==3)||(a[i-1][j]==4)||(a[i-1][j]==2)))
            {
                bool op1=func(a,i-1,j,n,m,visited);
                if(op1)
                {
                    return true;
                }
            }
            // i+1,j
            if((i+1<n)&&(!visited[i+1][j])&&((a[i+1][j]==5)||(a[i+1][j]==6)||(a[i+1][j]==2)))
            {
                bool op2=func(a,i+1,j,n,m,visited);
                if(op2)
                {
                    return true;
                }
            }
        }else if(cur==3)
        {
            // i+1,j
            if((i+1<n)&&(!visited[i+1][j])&&((a[i+1][j]==5)||(a[i+1][j]==6)||(a[i+1][j]==2)))
            {
                bool op1=func(a,i+1,j,n,m,visited);
                if(op1)
                {
                    return true;
                }
            }
            // i,j-1
            if((j-1>=0)&&(!visited[i][j-1])&&((a[i][j-1]==4)||(a[i][j-1]==6)||(a[i][j-1]==1)))
            {
                bool op2=func(a,i,j-1,n,m,visited);
                if(op2)
                {
                    return true;
                }
            }
        }else if(cur==4)
        {
            // i+1,j
            if((i+1<n)&&(!visited[i+1][j])&&((a[i+1][j]==5)||(a[i+1][j]==6)||(a[i+1][j]==2)))
            {
                bool op1=func(a,i+1,j,n,m,visited);
                if(op1)
                {
                    return true;
                }
            }
            // i,j+1
            if((j+1<m)&&(!visited[i][j+1])&&((a[i][j+1]==3||(a[i][j+1]==5)||(a[i][j+1]==1))))
            {
                bool op2=func(a,i,j+1,n,m,visited);
                if(op2)
                {
                    return true;
                }
            }
        }else if(cur==5)
        {
            // i,j-1
            if((j-1>=0)&&(!visited[i][j-1])&&((a[i][j-1]==4)||(a[i][j-1]==6)||(a[i][j-1]==1)))
            {
                bool op1=func(a,i,j-1,n,m,visited);
                if(op1)
                {
                    return true;
                }
            }
            // i-1,j
            if((i-1>=0)&&(!visited[i-1][j])&&((a[i-1][j]==3)||(a[i-1][j]==4)||(a[i-1][j]==2)))
            {
                bool op2=func(a,i-1,j,n,m,visited);
                if(op2)
                {
                    return true;
                }
            }
        }else if(cur==6){
            // i,j+1
            if((j+1<m)&&(!visited[i][j+1])&&((a[i][j+1]==3||(a[i][j+1]==5)||(a[i][j+1]==1))))
            {
                bool op1=func(a,i,j+1,n,m,visited);
                if(op1)
                {
                    return true;
                }
            }
            // i-1,j
            if((i-1>=0)&&(!visited[i-1][j])&&((a[i-1][j]==3)||(a[i-1][j]==4)||(a[i-1][j]==2)))
            {
                bool op2=func(a,i-1,j,n,m,visited);
                if(op2)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        return func(a,0,0,n,m,visited);
    }
};
