
bool isOk(bool edges[101][101],int *color,int cur_color,int sv,int n)
{
    for(int i=0;i<n;i++)
    {
        int adj=i;
        if((edges[sv][i])&&(sv!=i)&&color[adj]!=-1&&(color[adj]==cur_color))
        {
            return false;
        }
    }
    return true;
}

bool func(bool edges[101][101],int n,int sv,int *color,int m)
{
    if(sv==n)
    {
        return true;
    }
    for(int i=0;i<m;i++)
    {
        int cur_color=i;
        if(isOk(edges,color,cur_color,sv,n))
        {
            color[sv]=cur_color;
            bool ans=func(edges,n,sv+1,color,m);
            if(ans)
            {
                return true;
            }
            color[sv]=-1;
        }
    }
    return false;
}

bool graphColoring(bool edges[101][101], int m, int n)
{
    int *color=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            bool ans=func(edges,n,i,color,m);
            if(!ans)
            {
                return false;
            }
        }
    }
    return true;
}


bool isPossible(int pos_color,int sv,int *color,bool graph[101][101],int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[sv][i]&&(color[i]==pos_color))
        {
            return false;
        }
    }
    return true;
}
void func(bool graph[101][101],int n,int m,int *color,int sv,bool &done)
{
    if(sv==n)
    {
        done=true;
        return ;
    }
    for(int i=0;i<m;i++)
    {
        int pos_color=i;
        if(isPossible(pos_color,sv,color,graph,n))
        {
            color[sv]=pos_color;
            func(graph,n,m,color,sv+1,done);
            if(done)
            {
                return ;
            }else{
                color[sv]=-1;
            }
        }
    }
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int *color=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
    }
    bool done=false;
    func(graph,n,m,color,0,done);
    return done;
}

