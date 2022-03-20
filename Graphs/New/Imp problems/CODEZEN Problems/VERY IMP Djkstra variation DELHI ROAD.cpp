n DELHI, there are N junctions connected by M bi-directional roads. There is at most one road between any pair of junctions. There is no road connecting a junction to itself. The travel time for a road is the same in both directions.
At every junction there is a single traffic light. Starting from time 0, each light flashes green once every T time units, where the value of T is different for each junction.
A vehicle that is at a junction can start moving along a road only when the light at the current junction flashes green. If a vehicle arrives at a junction between green flashes, it must wait for the next green flash before continuing in any direction. If it arrives at a junction at exactly the same time that the light flashes green, it can immediately proceed along any road originating from that junction.
You are given a city map that shows travel times for all roads. For each junction i, you are given Ti, the time period between green flashes of the light at that junction. The light at junction i flashes green at times 0, Ti, 2Ti, 3Ti, ...
Your task is to find and print the minimum time taken from a given source junction to a given destination junction for a vehicle when the traffic starts. The junctions are identified by integers 1 through N

#include<bits/stdc++.h>
using namespace std;
int getMin(bool *visited,int *dist,int n)
{
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		if(!visited[i]&&(ans==-1||(dist[ans]>dist[i])))
		{
			ans=i;
		}
	}
	return ans;
}
int main() {
	int n,m;
	cin>>n>>m;
	int **edges=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	int *time=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>time[i];
	}
	int x,y,cost;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>cost;
		x--;y--;
		edges[x][y]=cost;
		edges[y][x]=cost;
	}
	cin>>x>>y;
	int sv=x-1,ev=y-1;
	bool *visited=new bool[n];
	int *dist=new int[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
		dist[i]=INT_MAX;
	}
	dist[sv]=0;
	int ans=INT_MAX;
	for(int i=0;i<(n-1);i++)
	{
		int minVertex=getMin(visited,dist,n);
		visited[minVertex]=true;
		for(int j=0;j<n;j++)
		{
			if(edges[minVertex][j]!=0)
			{
				int temp=dist[minVertex]+edges[minVertex][j];
				if(j==ev)
				{
					ans=min(ans,temp);
				}
				if(temp%(time[j])!=0)
				{
					temp=temp+time[j]-(temp%time[j]);
				}
				if(temp<(dist[j]))
				{
					dist[j]=temp;
				}
			}
		}
	}
	cout<<(ans)<<endl;
}












