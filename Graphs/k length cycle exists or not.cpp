

Gary has a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). 
Now Gary is getting bored and wants to play a game. The key of this game is to find a 
cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk 
a cycle if and only if it meets the following condition:

1. These k dots are different: if i ? j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 = i = k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. 
Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a 
cycle on the board.


bool func(vector<vector<char>> &a,int si,int sj,int ei,int ej,int n,int m,char ch,int len,bool **visited,int &ai,int &aj)
{
    visited[si][sj]=true;
    if((si==ei)&&(sj==ej)&&(len>=5))
    {
        return true;
    }
    if((sj+1<m)&&(a[si][sj+1]==ch)&&(!visited[si][sj+1]||((len>=4)&&(si==ai)&&(sj+1==aj))))
    {
        bool temp=func(a,si,sj+1,ei,ej,n,m,ch,len+1,visited,ai,aj);
        if(temp) return true;
    }
    if((si+1<n)&&(a[si+1][sj]==ch)&&(!visited[si+1][sj]||((len>=4)&&(si+1==ai)&&(sj==aj))))
    {
        bool temp=func(a,si+1,sj,ei,ej,n,m,ch,len+1,visited,ai,aj);
        if(temp) return true;
    }
    if((sj-1>=0)&&(a[si][sj-1]==ch)&&(!visited[si][sj-1]||((len>=4)&&(si==ai)&&(sj-1==aj))))
    {
        bool temp=func(a,si,sj-1,ei,ej,n,m,ch,len+1,visited,ai,aj);
        if(temp) return true;
    }
    if((si-1>=0)&&(a[si-1][sj]==ch)&&(!visited[si-1][sj]||((len>=4)&&(si-1==ai)&&(sj==aj))))
    {
        bool temp=func(a,si-1,sj,ei,ej,n,m,ch,len+1,visited,ai,aj);
        if(temp) return true;
    }
    return false;
}

bool hasCycle(vector<vector<char>> &a, int n, int m) {
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
            char ch=a[i][j];
            int a1=i;
            int b1=j;
            bool ans=func(a,i,j,i,j,n,m,ch,1,visited,a1,b1);
            if(ans)
            {
                return true;
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
    return false;
}


