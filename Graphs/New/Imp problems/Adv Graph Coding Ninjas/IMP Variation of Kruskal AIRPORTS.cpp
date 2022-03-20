
// hint video

#include<bits/stdc++.h>
using namespace std;
struct node{
    int sv,ev,wt;
};	
bool comparator(node a,node b)
{
    return a.wt<b.wt;
}
int getParent(int i,int *parent)
{
    if(i==parent[i])
    {
		return i;
    }
    return parent[i]=getParent(parent[i],parent);
}
int main()
{
    int t;
    cin>>t;
    int test=1;
    while(t--)
    {
        int n,m,cost;
        cin>>n>>m>>cost;
        node *edges=new node[m];
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            a--;b--;
            edges[i].sv=a;
            edges[i].ev=b;
            edges[i].wt=c;
        }
        sort(edges,edges+m,comparator);
        int ans=0;
        int *parent=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            node cur=edges[i];
         	int sv_par=getParent(cur.sv,parent),ev_par=getParent(cur.ev,parent);
            if(sv_par!=ev_par)
            {
                int cur_edge_wt=cur.wt;
                if(cur_edge_wt<cost)
                {
					parent[sv_par]=ev_par;
                    ans+=(cur_edge_wt);
                }
            }
        }
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(i==parent[i])
            {
                comp++;
            }
        }
        ans+=(comp*cost);
        cout<<"Case #"<<test<<": "<<ans<<' '<<comp<<endl;
        test++;
    }
	return 0;
}



























