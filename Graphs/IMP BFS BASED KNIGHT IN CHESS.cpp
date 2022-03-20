
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.

**************************************************

Assume this problem as searching in graph where each block of chess board is vertex.
How would you define edges in such a graph ?
When can you travel from vertex i to vertex j ?

Once you have the graph, then it reduces to finding the shortest path in an unweighted graph.
How do you find the shortest path in an unweighted graph ?



int Solution::knight(int n, int m, int si, int sj, int ei, int ej) {
    si--;sj--;ei--;ej--;
    int **a=new int*[n];
    int val=0;
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            a[i][j]=val++;
        }
    }
    vector<int> *edges=new vector<int>[(val)];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a1=a[i][j],b1;
            // i-1,j+2
            if((i-1>=0)&&(j+2<m))
            {
                b1=a[i-1][j+2];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i+1,j+2
            if((i+1<n)&&(j+2<m))
            {
                b1=a[i+1][j+2];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i+2,j+1
            if((i+2<n)&&(j+1<m))
            {
                b1=a[i+2][j+1];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i+2,j-1
            if((i+2<n)&&(j-1>=0))
            {
                b1=a[i+2][j-1];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i+1,j-2
            if((i+1<n)&&(j-2>=0))
            {
                b1=a[i+1][j-2];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i-1,j-2
            if((i-1>=0)&&(j-2>=0))
            {
                b1=a[i-1][j-2];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i-2,j-1
            if((i-2>=0)&&(j-1>=0))
            {
                b1=a[i-2][j-1];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
            // i-2,j+1
            if((i-2>=0)&&(j+1<m))
            {
                b1=a[i-2][j+1];
                edges[a1].push_back(b1);
                edges[b1].push_back(a1);
            }
        }
    }
    int sv=a[si][sj],ev=a[ei][ej];
    bool *visited=new bool[val];
    for(int i=0;i<val;i++)
    {
        visited[i]=false;
    }
    unordered_map<int,int> mp;
    queue<int> q;
    q.push(sv);
    mp[sv]=-1;
    visited[sv]=true;
    bool done=false;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==ev)
        {
            done=true;
            break;
        }
        for(int i=0;i<(edges[x].size());i++)
        {
            int adj=edges[x][i];
            if(!visited[adj])
            {
                q.push(adj);
                mp[adj]=x;
                visited[adj]=true;
            }
        }
    }
    if(!done)
    {
        return -1;
    }
    int steps=0;
    int c=ev;
    while(mp[c]!=-1)
    {
        steps++;
        c=mp[c];
    }
    return steps;
}

