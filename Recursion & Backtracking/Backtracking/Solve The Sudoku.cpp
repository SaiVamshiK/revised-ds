class Solution {
public:
    bool isPossible(vector<vector<char>> &mat,int row,int col,int val)
    {
        char ch=val+'0';
        for(int i=0;i<9;i++)
        {
            if(mat[row][i]==ch)
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(mat[i][col]==ch)
            {
                return false;
            }
        }
        int row_box=row/3,col_box=col/3;
        for(int i=(3*row_box);i<=(3*row_box+2);i++)
        {
            for(int j=(3*col_box);j<=(3*col_box+2);j++)
            {
                if(mat[i][j]==ch)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void func(vector<vector<char>> &mat,int row,int col,bool &ans)
    {
        if(col==9)
        {
            func(mat,row+1,0,ans);
            return ;
        }
        if(row==9)
        {
            ans=true;
            return ;
        }
        if(mat[row][col]=='.')
        {
            for(int i=1;i<=9;i++)
            {
                if(isPossible(mat,row,col,i))
                {
                    mat[row][col]=i+'0';
                    func(mat,row,col+1,ans);
                    if(ans)
                    {
                        return ;
                    }
                    mat[row][col]='.';
                }
            }
        }else{
            func(mat,row,col+1,ans);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans=false;
        func(board,0,0,ans);
    }
};
