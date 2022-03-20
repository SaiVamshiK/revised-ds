
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

***
We want minimal no. of edges to reach the destination so as graph is undirected and unweighted we have used a BFS(Level order
traversal)

#include<bits/stdc++.h>
using namespace std;
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
        int sv=0,ev=n-1;
        queue<int> q;
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        q.push(sv);
        visited[sv]=true;
        unordered_map<int,int> mp;
        mp[sv]=-1;
        bool done=false;
        while(!q.empty())
        {
			int cur=q.front();
            q.pop();
            if(cur==ev)
            {
                done=true;
                break;
            }
            for(int i=0;i<(edges[cur].size());i++)
            {
                int adj=edges[cur][i];
                if(!visited[adj])
                {
                    q.push(adj);
                    visited[adj]=true;
                    mp[adj]=cur;
                }
            }
        }
        if(!done)
        {
            cout<<0<<endl;
        }else{
			int ans=0;
            int q=ev;
            while(mp[q]!=-1)
            {
                ans++;
                q=mp[q];
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}




























