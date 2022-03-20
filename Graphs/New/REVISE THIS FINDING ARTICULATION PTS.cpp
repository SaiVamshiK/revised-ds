
Vice City is built over a group of islands, with bridges connecting them. As anyone in Vice City knows, the biggest fear of vice-citiers 
is that some day the islands will submerge. The big problem with this is that once the islands submerge, some of the other islands could 
get disconnected. You have been hired by the mayor of Vice city to tell him how many islands, when submerged, will disconnect parts of 
Vice City. You should know that initially all the islands of the city are connected.

Input
The input will consist of a series of test cases. Each test case will start with the number N (1 = N = 10^4) of islands, and the number M 
of bridges (1 = M = 10^5). Following there will be M lines each describing a bridge. Each of these M lines will contain two 
integers Ui, Vi (1 = Ui,Vi = N), indicating that there is a bridge connecting islands Ui and Vi. The input ends with a case where N = M = 0.

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,int sv,int par,int *disc,int *lowest,int &timer,set<int> &st)
{
	disc[sv]=timer;
	lowest[sv]=timer;
	timer++;
	int child_cnt=0;
	for(int i=0;i<(edges[sv].size());i++)
	{
		int adj=edges[sv][i];
		if(disc[adj]==-1)
		{
			// unvisited
			child_cnt++;
			dfs(edges,adj,sv,disc,lowest,timer,st);
			lowest[sv]=min(lowest[sv],lowest[adj]);
			if((sv!=0)&&lowest[adj]>=disc[sv])
			{
				st.insert(sv);
			}
		}else{
			if(par!=adj)
			{
				lowest[sv]=min(lowest[sv],disc[adj]);
			}
		}
	}
	if(par==-1)
	{
		if(child_cnt>=2)
		{
			st.insert(0);
		}
	}
}
int findArticulationPts(vector<int> *edges,int n)
{
	int *disc=new int[n];
	int *lowest=new int[n];
	for(int i=0;i<n;i++)
	{
		disc[i]=-1;
	}
	int timer=1,cnt=0;
	set<int> st;
	dfs(edges,0,-1,disc,lowest,timer,st);
	return st.size();
}
int main()
{
	int n,m;
	cin>>n>>m;
	while(n!=0&&(m!=0))
	{
		vector<int> *edges=new vector<int>[n];
		int a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			a--;b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		cout<<findArticulationPts(edges,n)<<endl;
		cin>>n>>m;
	}
}
