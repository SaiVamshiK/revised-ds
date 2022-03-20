
void func(int a[][20],int i,int j,int n,int **ans)
{
    if((i==n-1)&&(j==n-1))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<' ';
            }
        }
        cout<<endl;
        return ;
    }
    if((i+1<n)&&(a[i+1][j]==1)&&(ans[i+1][j]!=1))
    {
        ans[i+1][j]=1;
        func(a,i+1,j,n,ans);
        ans[i+1][j]=0;
    }
    if((j+1<n)&&(a[i][j+1]==1)&&(ans[i][j+1]!=1))
    {
        ans[i][j+1]=1;
        func(a,i,j+1,n,ans);
        ans[i][j+1]=0;
    }
    if((i-1>=0)&&(a[i-1][j]==1)&&(ans[i-1][j]!=1))
    {
        ans[i-1][j]=1;
        func(a,i-1,j,n,ans);
        ans[i-1][j]=0;
    }
    if((j-1>=0)&&(a[i][j-1]==1)&&(ans[i][j-1]!=1))
    {
        ans[i][j-1]=1;
        func(a,i,j-1,n,ans);
        ans[i][j-1]=0;
    }
}

void ratInAMaze(int a[][20], int n){
    if(a[0][0]==0)
    {
        return ;
    }
    int **ans=new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
        }
    }
    ans[0][0]=1;
    func(a,0,0,n,ans);
}
















