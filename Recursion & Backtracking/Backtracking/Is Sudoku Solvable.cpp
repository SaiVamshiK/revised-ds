
bool isPossible(int a[][9],int row,int col,int val)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==val)
        {
            return false;
        }
    }
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==val)
        {
            return false;
        }
    }
    int row_box=(row/3),col_box=(col/3);
    for(int i=(3*row_box);i<=(3*row_box+2);i++)
    {
        for(int j=(3*col_box);j<=(3*col_box+2);j++)
        {
            if(a[i][j]==val)
            {
                return false;
            }
        }
    }
    return true;
}

void func(int a[][9],int row,int col,bool &ans)
{
    if(col==9)
    {
        func(a,row+1,0,ans);
        return ;
    }
    if(row==9)
    {
        ans=true;
        return ;
    }
    if(a[row][col]==0){
        for(int i=1;i<=9;i++)
        {
            if(isPossible(a,row,col,i))
            {
                a[row][col]=i;
                func(a,row,col+1,ans);
                if(ans)
                {
                    return ;
                }
                a[row][col]=0;
            }
        }
    }else{
        func(a,row,col+1,ans);
    }
}

bool sudokuSolver(int a[][9]){
    bool ans=false;
    func(a,0,0,ans);
    return ans;
}

