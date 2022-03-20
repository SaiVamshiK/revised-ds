class Solution {
public:
    void dfs(int **edges,int n,int sv,stack<int> &st,bool *visited)
    {
        visited[sv]=true;
        for(int i=0;i<n;i++)
        {
            if(edges[sv][i]==1&&(!visited[i]))
            {
                dfs(edges,n,i,st,visited);
            }
        }
        st.push(sv);
    }
    void isCycle(int **edges,int n,int sv,bool *visited,bool &ans,bool *glo_vis)
    {
        visited[sv]=true;
        glo_vis[sv]=true;
        for(int i=0;i<n;i++)
        {
            if(edges[sv][i])
            {
                if(visited[i])
                {
                    ans=true;
                }else{
                    isCycle(edges,n,i,visited,ans,glo_vis);
                }
            }
            if(ans)
            {
                return ;
            }
        }
        visited[sv]=false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& vec) {
        vector<int> ans;
        if(n==0)
        {
            return ans;
        }
        int e=vec.size();
        int **edges=new int*[n];
        for(int i=0;i<n;i++)
        {
            edges[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                edges[i][j]=0;
            }
        }
        for(int i=0;i<(e);i++)
        {
            int x=vec[i][0],y=vec[i][1];
            edges[y][x]=1;
        }
        bool *vis=new bool[n];
        bool *glo_vis=new bool[n];
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            glo_vis[i]=false;
        }
        bool temp=false;
        for(int i=0;i<n;i++)
        {
            if(!glo_vis[i])
            {
                isCycle(edges,n,i,vis,temp,glo_vis);   
            }
            if(temp)
            {
                return ans;
            }
        }
        stack<int> st;
        bool *visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(edges,n,i,st,visited);
            }
        }
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
