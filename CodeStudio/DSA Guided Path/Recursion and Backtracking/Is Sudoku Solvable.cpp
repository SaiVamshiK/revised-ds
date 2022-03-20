bool isOk(int **a,int row,int col,int cur)
{
    for(int i=0;i<9;i++)
    {
		if(a[row][i]==cur)
        {
            return false;
        }
    }
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==cur)
        {
            return false;
        }
    }
    int rowBox=(row/3),colBox=(col/3);
    for(int i=(3*rowBox);i<=(3*rowBox+2);i++)
    {
        for(int j=(3*colBox);j<=(3*colBox+2);j++)
        {
            if(a[i][j]==cur)
            {
                return false;
            }
        }
    }
    return true;
}
bool func(int **a,int row,int col)
{
    if(row==9)
    {
        return true;
    }
    if(col==9)
    {
        return func(a,row+1,0);
    }
    if(a[row][col]!=0)
    {
        return func(a,row,col+1);
    }else{
        for(int i=1;i<=9;i++)
        {
            if(isOk(a,row,col,i))
            {
                a[row][col]=i;
                bool ans=func(a,row,col+1);
                if(ans)
                {
                    return ans;
                }
                a[row][col]=0;
            }
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    int **a=new int*[9];
    for(int i=0;i<9;i++)
    {
        a[i]=new int[9];
        for(int j=0;j<9;j++)
        {
            a[i][j]=matrix[i][j];
        }
    }
	return func(a,0,0);
}
















