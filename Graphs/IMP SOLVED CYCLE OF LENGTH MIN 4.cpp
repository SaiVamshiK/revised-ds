//find(vec,i,j,n,m,ch,visited,i,j,0,1);
pair<bool,int> find(vector<vector<char>> &edges,int i,int j,int n,int m,char ch,bool **visited,int ei,int ej,int can,int size)
{
    visited[i][j]=true;
    if((can!=0)&&(i==ei)&&(j==ej))
    {
        return {true,size};
    }
    if(((i+1<n)&&(!visited[i+1][j])&&(edges[i+1][j]==ch))||((i+1<n)&&(i+1==ei&&(j==ej))&&(can!=0)))
    {
        pair<bool,int> temp=find(edges,i+1,j,n,m,ch,visited,ei,ej,1,size+1);
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
        visited[i+1][j]=false;
    }
    if(((j+1<m)&&(!visited[i][j+1])&&(edges[i][j+1]==ch))||((j+1<m)&&(i==ei&&(j+1==ej))&&(can!=0)))
    {
        pair<bool,int> temp=find(edges,i,j+1,n,m,ch,visited,ei,ej,1,size+1);
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
        visited[i][j+1]=false;
    }
    if(((i-1>=0)&&(!visited[i-1][j])&&(edges[i-1][j]==ch))||((i-1>=0)&&(i-1==ei&&(j==ej))&&(can!=0)))
    {
        pair<bool,int> temp=find(edges,i-1,j,n,m,ch,visited,ei,ej,1,size+1);
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
        visited[i-1][j]=false;
    }
    if(((j-1>=0)&&(!visited[i][j-1])&&(edges[i][j-1]==ch))||((j-1>=0)&&(i==ei&&(j-1==ej))&&(can!=0)))
    {
        pair<bool,int> temp=find(edges,i,j-1,n,m,ch,visited,ei,ej,1,size+1);
        if(temp.first&&(temp.second>=4))
        {
            return temp;
        }
        visited[i][j-1]=false;
    }
    return {false,0};
}
bool hasCycle(vector<vector<char>> &vec, int n, int m) {
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
            if(!visited[i][j])
            {
                char ch=vec[i][j];
                pair<bool,int> ans=find(vec,i,j,n,m,ch,visited,i,j,0,1);
                if(ans.first)
                {
                    return true;
                }
            }
        }
    }
    return false;
}





















