
Its Gary's birthday today and he has ordered his 
favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother 
on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :

Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake

Output Format :

Size of the biggest piece of '1's and no '0's



int findCount(char mat[NMAX][NMAX],int n,int m,int i,int j,bool **visited)
{
    int cnt=1;
    visited[i][j]=true;
    if((i+1<n)&&(mat[i+1][j]=='1')&&(!visited[i+1][j]))
    {
        cnt=cnt+findCount(mat,n,m,i+1,j,visited);
    }
    if((j-1>=0)&&(mat[i][j-1]=='1')&&(!visited[i][j-1]))
    {
    	cnt=cnt+findCount(mat,n,m,i,j-1,visited);
    }
    if((i-1>=0)&&(mat[i-1][j]=='1')&&(!visited[i-1][j]))
    {
        cnt=cnt+findCount(mat,n,m,i-1,j,visited);
    }
    if((j+1<m)&&(mat[i][j+1]=='1')&&(!visited[i][j+1]))
    {
        cnt=cnt+findCount(mat,n,m,i,j+1,visited);
    }
    return cnt;
}
int solve(int n,char mat[NMAX][NMAX])
{
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
			visited[i][j]=false;
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
			if(mat[i][j]=='1')
            {
				ans=max(ans,findCount(mat,n,n,i,j,visited));
	        }
     		for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    visited[i][j]=false;
                }
            }       
        }
    }
    return ans;
}









