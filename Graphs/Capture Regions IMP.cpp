Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]
     
assume board a closed entity…where O represents opening or hole and X represent blockage… you sink board in water… 
water will only start filling from boundary O, it will penetrate deep if there is more O up,down,left,or right…whoever 
O got wet will remain in final matrix and those O which remained dry , will be transformed to X…there is not a clear explanation in question


void dfs(vector<vector<char> > &A,int i,int j,int n,int m,bool **visited)
{
    visited[i][j]=true;
    // i,j+1
    if((j+1<m)&&(!visited[i][j+1])&&(A[i][j+1]=='O'))
    {
        dfs(A,i,j+1,n,m,visited);
    }
    // i+1,j
    if((i+1<n)&&(!visited[i+1][j])&&(A[i+1][j]=='O'))
    {
        dfs(A,i+1,j,n,m,visited);
    }
    // i,j-1
    if((j-1>=0)&&(!visited[i][j-1])&&(A[i][j-1]=='O'))
    {
        dfs(A,i,j-1,n,m,visited);
    }
    // i-1,j
    if((i-1>=0)&&(!visited[i-1][j])&&(A[i-1][j]=='O'))
    {
        dfs(A,i-1,j,n,m,visited);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    int n=A.size();
    int m=A[0].size();
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i][0]=='O')    
        {
            dfs(A,i,0,n,m,visited);
        }
        if(A[i][m-1]=='O')
        {
            dfs(A,i,m-1,n,m,visited);
        }
    }
    for(int i=0;i<m;i++)
    {
        if(A[0][i]=='O')
        {
            dfs(A,0,i,n,m,visited);
        }
        if(A[n-1][i]=='O')
        {
            dfs(A,n-1,i,n,m,visited);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j])
            {
                A[i][j]='X';
            }
        }
    }
}

