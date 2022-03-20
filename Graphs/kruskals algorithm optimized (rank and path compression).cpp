




#include <bits/stdc++.h>
using namespace std;
struct Node{
    int sv,ev,wt;
};
bool compare(Node a,Node b)
{
    return a.wt<b.wt;
}
int getParent(int i,int *parent)
{
    if(i==parent[i])
    {
        return i;
    }
    parent[i]=getParent(parent[i],parent);
    return parent[i];
}
int main() {
    int n,e;
    cin>>n>>e;
    Node *edges=new Node[e];
    for(int i=0;i<e;i++)
    {
        cin>>edges[i].sv>>edges[i].ev>>edges[i].wt;
    }
    sort(edges,edges+e,compare);
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int *rank=new int[n];
    for(int i=0;i<n;i++)
    {
        rank[i]=1;
    }
    Node *ans=new Node[n-1];
    int cnt=0;
    int i=0;
    while(cnt!=(n-1))
    {
        Node cur_edge=edges[i];
        int sv=cur_edge.sv,ev=cur_edge.ev,wt=cur_edge.wt;
        int sv_par=getParent(sv,parent);
        int ev_par=getParent(ev,parent);
        if(sv_par!=ev_par)
        {
            ans[cnt++]=cur_edge;
            int r1=rank[sv_par],r2=rank[ev_par];
            if(r1<=r2)
            {
                // make b as parent of a
				parent[sv_par]=ev_par;
                rank[ev_par]+=rank[sv_par];
            }else{
                parent[ev_par]=sv_par;
                rank[sv_par]+=rank[ev_par];
            }
        }
        i++;
    }
    for(int i=0;i<(n-1);i++)
    {
        Node cur_edge=ans[i];
        if(cur_edge.sv<cur_edge.ev)
        {
            cout<<(cur_edge.sv)<<' '<<(cur_edge.ev)<<' '<<(cur_edge.wt)<<endl;
        }else{
            cout<<(cur_edge.ev)<<' '<<(cur_edge.sv)<<' '<<(cur_edge.wt)<<endl;
        }
    }
}

