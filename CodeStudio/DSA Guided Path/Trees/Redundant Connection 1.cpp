
Problem Statement
You are given a graph that started as a tree with ‘N’ nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N and was not an edge that already existed. The resulting graph is given as a 2D-array of edges ARR of size NX2. Each element of edges is a pair [u, v] with u < v, which represents an undirected edge connecting nodes u and v.
For the given graph you are required to find an edge that can be removed such that the graph becomes a tree of N nodes.

int getParent(int i,int *parent)
{
    if(i==parent[i])
    {
        return i;
    }
    return parent[i]=getParent(parent[i],parent);
}
vector<int> redundantConnection(vector<vector<int>> &a)
{
    int e=a.size();
    int n=e;
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<e;i++)
    {
        int sv=a[i][0],ev=a[i][1];
        sv--;ev--;
        int svPar=getParent(sv,parent),evPar=getParent(ev,parent);
        if(svPar!=evPar)
        {
         	parent[svPar]=evPar;
        }else{
            return a[i];
        }
    }
}



