


There are N cities numbered from 0 to N-1. 
You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.
Input Format

The first line contains two integers, N and M separated by a single space. M lines follow. 
Each line contains integers separated by a single space X and Y denoting road between X and Y.


#include<bits/stdc++.h>
using namespace std;
int find(int i,int *parent)
{
	if(i==parent[i])
	{
		return i;
	}
	return parent[i]=find(parent[i],parent);
}
int main() {
	int n,e;
	cin>>n>>e;
	int a,b;
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
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		int pa=find(a,parent),pb=find(b,parent);
		int rpa=rank[pa],rpb=rank[pb];
		if(pa!=pb)
		{
			if(rpa<=rpb)
			{
				parent[pa]=pb;
				rank[pb]+=rank[pa];
			}else{
				parent[pb]=pa;
				rank[pa]+=rank[pb];
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int temp;
		temp=(n-(rank[find(i,parent)]));
		ans+=temp;
	}
	cout<<ans/2;
	return 0;
}
