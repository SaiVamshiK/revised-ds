




#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *dist,int n)
{
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if((!visited[i])&&((ans==-1)||(dist[ans]>dist[i])))
        {
            ans=i;
        }
    }
    return ans;
}
int main() {
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        edges[a][b]=c;
        edges[b][a]=c;
    }
    int *dist=new int[n];
    dist[0]=0;
    for(int i=1;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    // {wt,node}
    set<pair<int,int>> st;
    st.insert({0,0});
    for(int i=0;i<(n-1);i++)
    {
        auto it=st.begin();
        int minVertex=(*it).second;
        visited[minVertex]=true;
        st.erase(st.begin());
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0&&(!visited[j]))
            {
				if((dist[j]>(edges[minVertex][j]+dist[minVertex])))
                {
                    int t=dist[j];
                    dist[j]=edges[minVertex][j]+dist[minVertex];
                    if(t!=INT_MAX)
                    {
                        st.erase(st.find({t,j}));
                    }
                    st.insert({dist[j],j});
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<(i)<<' '<<(dist[i])<<endl;
    }
}



