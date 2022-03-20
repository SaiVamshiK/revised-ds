
A group of hackers want hack a network connecting n cities. The network is such that there may or may not be a direct communication 
between two cities. But there is always a way to communicate from any city u to any other city v through a series of connections(For 
example, if the city 1 is directly connected to city 2 and city 2 is directly connected to city 3, then city 1 can communicate with city 
3 through city 2). There is a hacker in each of the n cities. They wanted to block some of the connections for hacking, also they want to 
remain connected through network, i.e. after blocking some connections, still there should be a way of communication from every city of every 
other city so that hackers can communicate.
Hackers know that there is a cost associated with each direct connection. Since they have a limited amount of money, s, they want block as many 
connections as they can. Help them find the number of connections they can block.

Input Format
First line contains n, m and s, denoting the number of cities, number of direct connections, and the amount of money hackers have. Next m 
lines contains 3 integers each, u, v and c, denoting that there is a direct connection between node u and node v and the cost of breaking 
this connection is c.

Constraints
1<=s, c<=10^12 1<=n<=50000 1<=m<=100000 1<=u,v<=n, edges are unique, and there is no self loop.

Output Format
On the first line, print the number of connections hackers can block, w and the minimum cost of blocking, c. Note that there can be multiple 
possible sets of w connections, which can be removed within the sum of costs, s. Consider that set, S, such that the total cost of blocking 
is minimum.

****************************** APPROACH *************************************
This question can be solved greedily by finding Maximum Spanning Tree, MST(which can be found using minimum spanning tree algorithms). 
For the graph to remain connected, leave the edges of the MST. Now sort the remaining edges in the increasing order of their cost, remove 
the edges until the sum of costs of removed edges doesn’t exceed the allowed total cost.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll sv,ev,wt;
};
bool comparator(node a,node b)
{
	return a.wt>b.wt;
}
ll getParent(ll i,ll *parent)
{
	if(i==parent[i])	
	{
		return i;
	}
	return parent[i]=getParent(parent[i],parent);
}
int main()
{
	ll n,m,sum;
	cin>>n>>m>>sum;
	ll x,y,z;
	node *edges=new node[m];
	for(ll i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		edges[i].sv=x;
		edges[i].ev=y;
		edges[i].wt=z;
	}
	sort(edges,edges+m,comparator);
	vector<node> ans;
	ll *parent=new ll[n];
	ll *rank=new ll[n];
	for(ll i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=1;
	}
	ll k=0;
	for(ll i=0;i<m;i++)
	{
		node cur_edge=edges[i];
		ll sv_par=getParent(cur_edge.sv,parent),ev_par=getParent(cur_edge.ev,parent);
		if(sv_par!=ev_par)
		{
			if(rank[sv_par]<rank[ev_par])
			{
				parent[sv_par]=ev_par;
				rank[ev_par]+=rank[sv_par];
			}else{
				parent[ev_par]=sv_par;
				rank[sv_par]+=rank[ev_par];
			}
		}else{
			ans.push_back(cur_edge);
		}
	}
	reverse(ans.begin(),ans.end());
	ll req=0,cnt=0;;
	for(ll i=0;i<(ans.size());i++)
	{
		if(req+ans[i].wt>sum)
		{
			break;
		}
		req+=ans[i].wt;
        cnt++;
	}
	cout<<cnt<<' '<<req;
}






