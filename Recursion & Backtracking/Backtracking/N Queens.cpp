bool isPossible(int **a,int row,int col,int n)
{
	for(int i=0;i<n;i++)
    {
        if(a[row][i]==1)
        {
            return false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i][col]==1)
        {
            return false;
        }
    }
    int i=row,j=col;
    while((i>=0)&&(j<n))
    {
        if(a[i][j]==1)
        {
            return false;
        }
        i--;j++;
    }
    i=row;j=col;
    while((i>=0)&&(j>=0))
    {
        if(a[i][j]==1)
        {
            return false;
        }
        i--;j--;
    }
    return true;
}
void func(int **a,int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<' ';
            }
        }
        cout<<endl;
        return ;
    }
    for(int col=0;col<n;col++)
    {
        if(isPossible(a,row,col,n))
        {
            a[row][col]=1;
            func(a,n,row+1);
            a[row][col]=0;
        }
    }
}
void placeNQueens(int n){
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    func(a,n,0);
}



