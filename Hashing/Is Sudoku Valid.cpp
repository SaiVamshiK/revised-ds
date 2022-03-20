Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

bool isValidH(vector<string> &a,int row,char ch)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==ch)
        {
            return false;
        }
    }
    return true;
}
bool isValidV(vector<string> &a,int col,char ch)
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==ch)
        {
            return false;
        }
    }
    return true;
}
bool isValidB(vector<string> &a,int row_box,int col_box,char ch)
{
    for(int i=(3*row_box);i<=((3*row_box)+2);i++)
    {
        for(int j=(3*col_box);j<=((3*col_box)+2);j++)
        {
            if(a[i][j]==ch)
            {
                return false;
            }
        }
    }
    return true;
}
bool isValid(vector<string> &a,int row,int col)
{
    if(row==9)
    {
        return true;
    }
    if(a[row][col]!='.')
    {
        if(col==8)
        {
            return isValid(a,row+1,col);
        }else{
            return isValid(a,row,col+1);
        }
    }else{
        int row_box=(row/3);
        int col_box=(col/3);
        for(int i=1;i<=9;i++)
        {
            char ch='0'+i;
            if(isValidH(a,row,ch)&&(isValidV(a,col,ch))&&(isValidB(a,row_box,col_box,ch)))
            {
                a[row][col]=ch;
                bool ans=false;
                if(col==8)
                {
                    ans=isValid(a,row+1,col);
                }else{
                    ans=isValid(a,row,col+1);
                }
                if(ans)
                {
                    return ans;
                }
                a[row][col]='.';
            }
        }
    }
    return false;
}


********************************	INTERVIEWBIT SOLUTION CAN BE THIS ALSO	********************************


bool isVH(vector<string> &a,int row,char ch,int col)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==ch&&(i!=col))
        {
            return false;
        }
    }
    return true;
}
bool isVV(vector<string> &a,int col,char ch,int row)
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==ch&&(i!=row))
        {
            return false;
        }
    }
    return true;
}
bool isVB(vector<string> &a,int row_box,int col_box,char ch,int row,int col)
{
    for(int i=(3*row_box);i<=((3*row_box)+2);i++)
    {
        for(int j=(3*col_box);j<=((3*col_box)+2);j++)
        {
            if((i!=row)&&(j!=col)&&a[i][j]==ch)
            {
                return false;
            }
        }
    }
    return true;
}
int Solution::isValidSudoku(const vector<string> &arr) {
    vector<string> a;
    for(int i=0;i<(arr.size());i++)
    {
        a.push_back(arr[i]);
    }
    int n=9,m=9;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]!='.')
            {
                int row=i,col=j;
                int row_box=(row/3),col_box=(col/3);
if((isVH(a,row,a[row][col],col)&&(isVV(a,col,a[row][col],row))&&(isVB(a,row_box,col_box,a[row][col],row,col))))
{
    
}else{
    return false;
}
            }
        }
    }
    return isValid(a,0,0);
}

bool isValidH(vector<string> &a,int row,char ch)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==ch)
        {
            return false;
        }
    }
    return true;
}
bool isValidV(vector<string> &a,int col,char ch)
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==ch)
        {
            return false;
        }
    }
    return true;
}
bool isValidB(vector<string> &a,int row_box,int col_box,char ch)
{
    for(int i=(3*row_box);i<=((3*row_box)+2);i++)
    {
        for(int j=(3*col_box);j<=((3*col_box)+2);j++)
        {
            if(a[i][j]==ch)
            {
                return false;
            }
        }
    }
    return true;
}
bool isValid(vector<string> &a,int row,int col)
{
    if(row==9)
    {
        return true;
    }
    if(a[row][col]!='.')
    {
        if(col==8)
        {
            return isValid(a,row+1,col);
        }else{
            return isValid(a,row,col+1);
        }
    }else{
        int row_box=(row/3);
        int col_box=(col/3);
        for(int i=1;i<=9;i++)
        {
            char ch='0'+i;
            if(isValidH(a,row,ch)&&(isValidV(a,col,ch))&&(isValidB(a,row_box,col_box,ch)))
            {
                a[row][col]=ch;
                bool ans=false;
                if(col==8)
                {
                    ans=isValid(a,row+1,col);
                }else{
                    ans=isValid(a,row,col+1);
                }
                if(ans)
                {
                    return ans;
                }
                a[row][col]='.';
            }
        }
    }
    return false;
}
bool isVH(vector<string> &a,int row,char ch,int col)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==ch&&(i!=col))
        {
            return false;
        }
    }
    return true;
}
bool isVV(vector<string> &a,int col,char ch,int row)
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==ch&&(i!=row))
        {
            return false;
        }
    }
    return true;
}
bool isVB(vector<string> &a,int row_box,int col_box,char ch,int row,int col)
{
    for(int i=(3*row_box);i<=((3*row_box)+2);i++)
    {
        for(int j=(3*col_box);j<=((3*col_box)+2);j++)
        {
            if((i!=row)&&(j!=col)&&a[i][j]==ch)
            {
                return false;
            }
        }
    }
    return true;
}
int Solution::isValidSudoku(const vector<string> &arr) {
    vector<string> a;
    for(int i=0;i<(arr.size());i++)
    {
        a.push_back(arr[i]);
    }
    int n=9,m=9;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]!='.')
            {
                int row=i,col=j;
                int row_box=(row/3),col_box=(col/3);
if((isVH(a,row,a[row][col],col)&&(isVV(a,col,a[row][col],row))&&(isVB(a,row_box,col_box,a[row][col],row,col))))
{
    
}else{
    return false;
}
            }
        }
    }
    return true;
    return isValid(a,0,0);
}


