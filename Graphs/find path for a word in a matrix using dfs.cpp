
Given a NxM matrix containing Uppercase English Alphabets only. 
Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

bool exists(char mat[][MAXN],int n,int m,int i,int j,bool **visited,char s[])
{
    bool ans=false;
    visited[i][j]=true;
    if(s[0]=='\0')
    {
        return true;
    }
	if((j+1<m)&&(mat[i][j+1]==s[0])&&(!visited[i][j+1]))
    {
        ans=ans||(exists(mat,n,m,i,j+1,visited,s+1));
    }
    if((i+1<n)&&(j+1<m)&&(mat[i+1][j+1]==s[0])&&(!visited[i+1][j+1]))
    {
        ans=ans||(exists(mat,n,m,i+1,j+1,visited,s+1));
    }
    if((i+1<n)&&(mat[i+1][j]==s[0])&&(!visited[i+1][j]))
    {
        ans=ans||(exists(mat,n,m,i+1,j,visited,s+1));
    }
    if((i+1<n)&&(j-1>=0)&&(mat[i+1][j-1]==s[0])&&(!visited[i+1][j-1]))
    {
        ans=ans||(exists(mat,n,m,i+1,j-1,visited,s+1));
    }
    if((j-1>=0)&&(mat[i][j-1]==s[0])&&(!visited[i][j-1]))
    {
        ans=ans||(exists(mat,n,m,i,j-1,visited,s+1));
    }
    if((i-1>=0)&&(j-1>=0)&&(mat[i-1][j-1]==s[0])&&(!visited[i-1][j-1]))
    {
        ans=ans||(exists(mat,n,m,i-1,j-1,visited,s+1));
    }
    if((i-1>=0)&&(mat[i-1][j]==s[0])&&(!visited[i-1][j]))
    {
        ans=ans||(exists(mat,n,m,i-1,j,visited,s+1));
    }
    if((i-1>=0)&&(j+1<m)&&(mat[i-1][j+1]==s[0])&&(!visited[i-1][j+1]))
    {
        ans=ans||(exists(mat,n,m,i-1,j+1,visited,s+1));
    }
    return ans;
}
int solve(char mat[][MAXN],int N, int M)
{
	bool **visited=new bool*[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=new bool[M];
        for(int j=0;j<M;j++)
        {
            visited[i][j]=false;
        }
    }
    char arr[]="CODINGNINJA";
    for(int i=0;i<N;i++)
    {
		for(int j=0;j<M;j++)
        {
            if(mat[i][j]=='C')
            {
                if(exists(mat,N,M,i,j,visited,arr+1))
                {
                    return 1;
                }
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<M;j++)
                    {
                        visited[i][j]=false;
                    }
                }
            }
        }
    }
    return 0;
}




