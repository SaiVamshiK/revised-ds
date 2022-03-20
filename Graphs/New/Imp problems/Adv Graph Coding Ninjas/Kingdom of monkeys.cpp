
You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.

***
Normal connected components problem with some variation

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,bool *visited,int sv,long &temp,long *arr)
{
    visited[sv]=true;
    temp+=arr[sv];
    for(int i=0;i<(edges[sv].size());i++)
    {
        int adj=edges[sv][i];
        if(!visited[adj])
        {
            dfs(edges,visited,adj,temp,arr);
        }
    }
}
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m;
        vector<int> *edges=new vector<int>[n];
        for(int i=0;i<m;i++)
        {
			cin>>x>>y;
            x--;y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        long *arr=new long[n];
        for(int i=0;i<n;i++)
        {
			cin>>arr[i];
        }
        long ans=INT_MIN;
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                long temp=0;
                dfs(edges,visited,i,temp,arr);
                ans=max(ans,temp);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}






























