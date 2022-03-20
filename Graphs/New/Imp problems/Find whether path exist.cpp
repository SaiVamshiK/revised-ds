Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.

class Solution {
public:
    
    void func(vector<vector<int>> &vec,int i,int j,int ei,int ej,int n,int m,bool **visited,bool &done)
    {
        visited[i][j]=true;
        if((i==ei)&&(j==ej))
        {
            done=true;
            return ;
        }
        if((i+1<n)&&(!visited[i+1][j])&&(vec[i+1][j]!=0))
        {
            func(vec,i+1,j,ei,ej,n,m,visited,done);
            if(done)
            {
                return ;
            }
        }
        if((j+1<m)&&(!visited[i][j+1])&&(vec[i][j+1]!=0))
        {
            func(vec,i,j+1,ei,ej,n,m,visited,done);
            if(done)
            {
                return ;
            }
        }
        if((i-1>=0)&&(!visited[i-1][j])&&(vec[i-1][j]!=0))
        {
            func(vec,i-1,j,ei,ej,n,m,visited,done);
            if(done)
            {
                return ;
            }
        }
        if((j-1>=0)&&(!visited[i][j-1])&&(vec[i][j-1]!=0))
        {
            func(vec,i,j-1,ei,ej,n,m,visited,done);
            if(done)
            {
                return ;
            }
        }
    }
    bool is_Possible(vector<vector<int>>& vec) {
        int n=vec.size(),m=vec[0].size();
        int si,sj,ei,ej;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vec[i][j]==1)
                {
                    si=i;
                    sj=j;
                }
                if(vec[i][j]==2)
                {
                    ei=i;
                    ej=j;
                }
            }
        }
        bool **visited=new bool*[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new bool[m];
            for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
            }
        }
        bool done=false;
        func(vec,si,sj,ei,ej,n,m,visited,done);
        return done;
    }
};



