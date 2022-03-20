#include<bits/stdc++.h>
using namespace std;
struct edge{
  	int sv,ev,wt;  
};
bool compare(edge a,edge b)
{
    return a.wt<b.wt;
}
int getParent(int i,int *parent)
{
    if(i==parent[i])
    {
        return i;
    }
    return getParent(parent[i],parent);
}
void kruskals(edge* edges,int n,int e)
{
    sort(edges,edges+e,compare);
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    edge* output=new edge[n-1];
    int count=0,i=0;
    while(count!=n-1)
    {
		edge cur_edge=edges[i];
        int sv_par=getParent(cur_edge.sv,parent);
        int ev_par=getParent(cur_edge.ev,parent);
        if(sv_par!=ev_par)
        {
            output[count++]=cur_edge;
            parent[sv_par]=ev_par;
        }
        i++;
    }
    for(int i=0;i<(n-1);i++)
    {
        edge cur_edge=output[i];
        if(cur_edge.sv<cur_edge.ev)
        {
            cout<<cur_edge.sv<<' '<<cur_edge.ev<<' '<<cur_edge.wt<<endl;
        }else{
            cout<<cur_edge.ev<<' '<<cur_edge.sv<<' '<<cur_edge.wt<<endl;
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    edge *edges=new edge[e];
    for(int i=0;i<e;i++)
    {
        int si,ei,wt;
        cin>>si>>ei>>wt;
        edges[i].sv=si;
        edges[i].ev=ei;
        edges[i].wt=wt;
    }
    kruskals(edges,n,e);
  	return 0;
}

