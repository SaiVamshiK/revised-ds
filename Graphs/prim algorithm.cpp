



#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool *visited,int *wt,int n)
{
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if((!visited[i])&&(ans==-1||(wt[ans]>wt[i])))
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
    bool *visited=new bool[n];
    int *wt=new int[n];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=INT_MAX;
    }
    parent[0]=-1;
    set<pair<int,int>> st;
    st.insert({0,0});
    for(int i=0;i<n;i++)
    {
        auto it=st.begin();
        int minVertex=(*it).second;
        st.erase(st.begin());
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0&&(!visited[j]))
            {
				if(wt[j]>edges[minVertex][j])
                {
                    int t=wt[j];
                    wt[j]=edges[minVertex][j];
                    if(t!=INT_MAX)
                    {
						st.erase(st.find({t,j}));
                    }
                    st.insert({wt[j],j});
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(i<parent[i])
        {
			cout<<(i)<<' '<<parent[i]<<' '<<wt[i]<<endl;
        }else{
            cout<<parent[i]<<' '<<i<<' '<<wt[i]<<endl;
        }
    }
}






