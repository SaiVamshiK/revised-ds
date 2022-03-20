#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,bool *visited,int sv,int *tin,int *tout,int &timer)
{
	visited[sv]=true;
	tin[sv]=timer;
	timer++;
	for(int i=0;i<(edges[sv].size());i++)
	{
		int adj=edges[sv][i];
		if(!visited[adj])
		{
			dfs(edges,visited,adj,tin,tout,timer);
		}
	}
	tout[sv]=timer;
	timer++;
}
int main()
{
	int n,a,b;
	cin>>n;
	vector<int> *edges=new vector<int>[n];
	for(int i=0;i<(n-1);i++)
	{
		cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	int *tin=new int[n];
	int *tout=new int[n];
	int timer=1;
	dfs(edges,visited,0,tin,tout,timer);
	int q;
	cin>>q;
    int o,x,y;
	while(q--)
	{
		cin>>o>>x>>y;
		x--;y--;
		int sv=y,ev=x;
		if(o==1)
		{
			if(tin[sv]<tin[ev]&&(tout[sv]>tout[ev]))
			{
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}else{
			if(tin[ev]<tin[sv]&&(tout[ev]>tout[sv]))
			{
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
}
















