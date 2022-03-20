
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). 
Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,int sv,unordered_set<int> &temp,bool *visited){
    visited[sv]=true;
    temp.insert(sv);
    for(int i=0;i<(edges[sv].size());i++)
    {
        if((!visited[edges[sv][i]]))
        {
            dfs(edges,edges[sv][i],temp,visited);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        int *p=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        int *q=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>q[i];
        }
        vector<int> *edges=new vector<int>[n];
        int a,b;
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            a--;b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        vector<unordered_set<int>> ans;
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                unordered_set<int> temp;
                dfs(edges,i,temp,visited);
                ans.push_back(temp);
            }
        }
        for(int i=0;i<(ans.size());i++)
        {
            unordered_set<int> temp=ans[i];
            unordered_set<int> p_set,q_set;
            for(auto it=temp.begin();it!=temp.end();it++)
            {
                int ind=(*it);
                p_set.insert(p[ind]);
                q_set.insert(q[ind]);
            }
            for(auto it=p_set.begin();it!=p_set.end();it++)
            {
                int elem=(*it);
                if((q_set.find(elem))==q_set.end())
                {
                    cout<<"NO\n";
                    goto z;
                }
            }
        }
        cout<<"YES\n";
        z:{
            
        }
    }
	return 0;
}

















