


It's Gary's birthday today and he has ordered his favourite square cake 
consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an 
edge with each other on the cake. Given the size of cake N and the cake, can you find the count 
of '1's in the biggest piece of '1's for Gary ?




int func(vector<vector<int>> &a,int si,int sj,int n,int m,bool **visited)
{
    visited[si][sj]=true;
    int ans=1;
    if((sj+1<m)&&(a[si][sj+1]==1)&&(!visited[si][sj+1]))
    {
        ans+=func(a,si,sj+1,n,m,visited);
    }
    // if((si+1<n)&&(sj+1<m)&&(a[si+1][sj+1]==1)&&(!visited[si+1][sj+1]))
    // {
    //     ans+=func(a,si+1,sj+1,n,m,visited);
    // }
    if((si+1<n)&&(a[si+1][sj]==1)&&(!visited[si+1][sj]))
    {
        ans+=func(a,si+1,sj,n,m,visited);
    }
    // if((si+1<n)&&(sj-1>=0)&&(a[si+1][sj-1]==1)&&(!visited[si+1][sj-1]))
    // {
    //     ans+=func(a,si+1,sj-1,n,m,visited);
    // }
    if((sj-1>=0)&&(a[si][sj-1]==1)&&(!visited[si][sj-1]))
    {
        ans+=func(a,si,sj-1,n,m,visited);
    }
    // if((si-1>=0)&&(sj-1>=0)&&(a[si-1][sj-1]==1)&&(!visited[si-1][sj-1]))
    // {
    //     ans+=func(a,si-1,sj-1,n,m,visited);
    // }
    if((si-1>=0)&&(a[si-1][sj]==1)&&(!visited[si-1][sj]))
    {
        ans+=func(a,si-1,sj,n,m,visited);
    }
    // if((si-1>=0)&&(sj+1<m)&&(a[si-1][sj+1]==1)&&(!visited[si-1][sj+1]))
    // {
    //     ans+=func(a,si-1,sj+1,n,m,visited);
    // }
    return ans;
}


int getBiggestPieceSize(vector<vector<int>> &a, int n) {
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
            visited[i][j]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                int temp=func(a,i,j,n,n,visited);
                ans=max(ans,temp);
                // no need to update visited vector to false again
            }
        }
    }
    return ans;
}




