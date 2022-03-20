
Given any source point, (C, D) and destination point, (E, F) on a chess board, 
we need to find whether Knight can move to the destination or not.

typedef pair<int,int> pi;
int Solution::knight(int n, int m, int si, int sj, int ei, int ej) {
    si--;sj--;
    ei--;ej--;
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    queue<pi> q;
    map<pi,pi> mp;
    q.push({si,sj});
    visited[si][sj]=true;
    mp[{si,sj}]={-1,-1};
    bool done=false;
    while(!q.empty())
    {
        pi x=q.front();
        q.pop();
        int i=x.first,j=x.second;
        if(i==ei&&(j==ej))
        {
            done=true;
            break;
        }
        // i-1,j+2
        if((i-1>=0)&&(j+2<m)&&(!visited[i-1][j+2]))
        {
            q.push({i-1,j+2});
            visited[i-1][j+2]=true;
            mp[{i-1,j+2}]=x;
        }
        // i+1,j+2
        if((i+1<n)&&(j+2<m)&&(!visited[i+1][j+2]))
        {
            q.push({i+1,j+2});
            visited[i+1][j+2]=true;
            mp[{i+1,j+2}]=x;
        }
        // i+2,j+1
        if((i+2<n)&&(j+1<m)&&(!visited[i+2][j+1]))
        {
            q.push({i+2,j+1});
            visited[i+2][j+1]=true;
            mp[{i+2,j+1}]=x;
        }
        // i+2,j-1
        if((i+2<n)&&(j-1>=0)&&(!visited[i+2][j-1]))
        {
            q.push({i+2,j-1});
            visited[i+2][j-1]=true;
            mp[{i+2,j-1}]=x;
        }
        // i+1,j-2
        if((i+1<n)&&(j-2>=0)&&(!visited[i+1][j-2]))
        {
            q.push({i+1,j-2});
            visited[i+1][j-2]=true;
            mp[{i+1,j-2}]=x;
        }
        // i-1,j-2
        if((i-1>=0)&&(j-2>=0)&&(!visited[i-1][j-2]))
        {
            q.push({i-1,j-2});
            visited[i-1][j-2]=true;
            mp[{i-1,j-2}]=x;
        }
        // i-2,j-1
        if((i-2>=0)&&(j-1>=0)&&(!visited[i-2][j-1]))
        {
            q.push({i-2,j-1});
            visited[i-2][j-1]=true;
            mp[{i-2,j-1}]=x;
        }
        // i-2,j+1
        if((i-2>=0)&&(j+1<m)&&(!visited[i-2][j+1]))
        {
            q.push({i-2,j+1});
            visited[i-2][j+1]=true;
            mp[{i-2,j+1}]=x;
        }
    }
    if(!done)
    {
        return -1;
    }
    int cnt=0;
    pi x={ei,ej};
    while((mp[x].first!=-1)&&(mp[x].first!=-1))
    {
        cnt++;
        x=mp[x];
    }
    return cnt;
}

