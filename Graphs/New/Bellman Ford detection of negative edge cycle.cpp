
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, 
the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.

struct node{
    int sv,ev,wt;  
};

class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>> a){
	    int e=a.size();
	    node *edges=new node[e];
	    for(int i=0;i<e;i++)
	    {
	        edges[i].sv=a[i][0];
	        edges[i].ev=a[i][1];
	        edges[i].wt=a[i][2];
	    }
	    int *dist=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        dist[i]=INT_MAX;
	    }
	    dist[0]=0;
	    for(int j=0;j<(n-1);j++)
	    {
	        bool isUpdated=false;
	        for(int i=0;i<e;i++)
	        {
	            node cur=edges[i];
	            // u to v
	            int u=cur.sv,v=cur.ev,wt=cur.wt;
	            if((dist[u]!=INT_MAX)&&dist[v]>(dist[u]+wt))
	            {
	                isUpdated=true;
	                dist[v]=dist[u]+wt;
	            }
	        }
	        if(!isUpdated)
	        {
	            return 0;
	        }
	    }
	    for(int i=0;i<e;i++)
	    {
	        node cur=edges[i];
	        int u=cur.sv,v=cur.ev,wt=cur.wt;
	        if(dist[v]>(dist[u]+wt))
	        {
	            return 1;
	        }
	    }
	    return 0;
	}
};

struct node{
    int sv,ev,wt;  
};
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>vec){
	    int m=vec.size();
	    node *edges=new node[m];
	    for(int i=0;i<m;i++)
	    {
	        edges[i].sv=vec[i][0];
	        edges[i].ev=vec[i][1];
	        edges[i].wt=vec[i][2];
	    }
	    int wt[n];
	    int parent[n];
	    for(int i=0;i<n;i++)
	    {
	        wt[i]=INT_MAX;
	    }
	    wt[0]=0;
	    parent[0]=-1;
	    bool up;
	    for(int i=0;i<(n-1);i++)
	    {
	        up=false;
	        for(int j=0;j<m;j++)
	        {
	            node cur=edges[j];
	            int s=cur.sv,e=cur.ev,w=cur.wt;
	            if((wt[s]!=INT_MAX)&&wt[e]>(wt[s]+w))
	            {
	                wt[e]=wt[s]+w;
	                parent[e]=s;
	                up=true;
	            }
	        }
	        if(up==false)
	        {
	            return 0;
	        }
	    }
	    for(int i=0;i<m;i++)
	    {
	        node cur=edges[i];
	        int s=cur.sv,e=cur.ev,w=cur.wt;
	        if((wt[s]!=INT_MAX)&&wt[e]>(wt[s]+w))
            {
                return 1;
            }
	    }
	    
	    return 0;
	}
};

