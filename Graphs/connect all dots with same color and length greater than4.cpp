Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1,?d2,?...,?dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i???j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1?=?i?=?k?-?1: di and di?+?1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge

pair<bool,int> exists(char mat[][MAXN],int n, int m,int i,int j,char ch,bool **visited,int len,int ei,int ej,int flag)
{
    if(flag!=0)
    {
     	visited[i][j]=true;   
    }
	if(flag!=0&&(i==ei)&&(j==ej))
    {
        return {true,len};
    }
    int ans_len=1;
    bool ans=false;
    if((j+1<m)&&(mat[i][j+1]==ch)&&(!visited[i][j+1]))
    {
        pair<bool,int> temp=(exists(mat,n,m,i,j+1,ch,visited,len+1,ei,ej,1));
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
    }
    if((i+1<n)&&(mat[i+1][j]==ch)&&(!visited[i+1][j]))
    {
        pair<bool,int> temp=(exists(mat,n,m,i+1,j,ch,visited,len+1,ei,ej,1));
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
    }
    if((j-1>=0)&&(mat[i][j-1]==ch)&&(!visited[i][j-1]))
    {
        pair<bool,int> temp=(exists(mat,n,m,i,j-1,ch,visited,len+1,ei,ej,1));
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
    }
    if((i-1>=0)&&(mat[i-1][j]==ch)&&(!visited[i-1][j]))
    {
        pair<bool,int> temp=(exists(mat,n,m,i-1,j,ch,visited,len+1,ei,ej,1));
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
    }
    return {ans,ans_len};
}
int solve(char mat[][MAXN],int n, int m)
{
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
        for(int j=0;j<m;j++)
        {
            int len=1;
            int flag=0;
            pair<bool,int> qwe=exists(mat,n,m,i,j,mat[i][j],visited,len,i,j,flag);
            if(qwe.first&&(qwe.second>=4))
            {
                return 1;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    visited[i][j]=false;
                }
            }
        }
    }
    return 0;
}
