
bool isPossible(int idx,int cur_color,bool graph[101][101],int n,int *color)
{
    for(int i=0;i<n;i++)
    {
        if(graph[idx][i])
        {
            if(color[i]==cur_color)
            {
                return false;
            }
        }
    }
    return true;
}
bool func(bool graph[101][101],int idx,int n,int *color,int m)
{
    if(idx==n)
    {
        return true;
    }
    for(int i=0;i<m;i++)
    {
        int cur_color=i;
        if(isPossible(idx,cur_color,graph,n,color))
        {
            color[idx]=cur_color;
            bool ans=func(graph,idx+1,n,color,m);
            if(ans)
            {
                return true;
            }
            color[idx]=-1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101],int m,int n)
{
    int *color=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
    }
    return func(graph,0,n,color,m);
}

