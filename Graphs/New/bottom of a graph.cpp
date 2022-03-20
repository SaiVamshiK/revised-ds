#include<bits/stdc++.h>
using namespace std;
// dfs(edges,n,visited,i,s);
void dfs(int **edges,int n,bool *visited,int sv,stack<int> &s)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1&&(!visited[i]))
        {
            dfs(edges,n,visited,i,s);
        }
    }
    s.push(sv);
}
// dfs1(transpose,n,visited,x,temp);
void dfs1(int **edges,int n,bool *visited,int sv,unordered_set<int> &temp)
{
    visited[sv]=true;
    temp.insert(sv);
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1&&(!visited[i]))
        {
            dfs1(edges,n,visited,i,temp);
        }
    }
}
int main()
{
	int n;
    cin>>n;
    while(n!=0)
    {
        int m,a,b;
        cin>>m;
        int **edges=new int*[n];
        for(int i=0;i<n;i++)
        {
            edges[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                edges[i][j]=0;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            a--;b--;
            edges[a][b]=1;
        }
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        stack<int> s;
        for(int i=0;i<n;i++)
        {
			if(!visited[i])
            {
                dfs(edges,n,visited,i,s);
            }
        }
        int **transpose=new int*[n];
        for(int i=0;i<n;i++)
        {
            transpose[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                transpose[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                transpose[i][j]=edges[j][i];
            }
        }
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        vector<unordered_set<int>> comps;
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
            if(!visited[x])
            {
                unordered_set<int> temp;
                dfs1(transpose,n,visited,x,temp);
                comps.push_back(temp);
            }
        }
        set<int> ans;
        for(auto it=comps.begin();it!=comps.end();it++)
        {
            unordered_set<int> temp;
			temp=(*it);
            bool done=false;
            for(auto it1=temp.begin();it1!=temp.end();it1++)
            {
                int elem=(*it1);
                for(int i=0;i<n;i++)
                {
                    if(edges[elem][i]==1&&(temp.find(i)==temp.end()))
                    {
                        done=true;
                        break;
                    }
                }
                if(done)
                {
                    break;
                }
            }
            if(!done)
            {
                for(auto it1=temp.begin();it1!=temp.end();it1++)
                {
                    ans.insert((*it1));
                }
            }
        }
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            cout<<(*it)+1<<' ';
        }
        cout<<endl;
		cin>>n;
    }
	return 0;
}


























