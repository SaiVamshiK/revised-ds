
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
return any of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    void dfs(vector<int> *edges,int sv,bool *visited,stack<int> &ans)
    {
        visited[sv]=true;
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            if(!visited[adj])
            {
                dfs(edges,adj,visited,ans);
            }
        }
        ans.push(sv);
    }
    void func(vector<int> *edges,int sv,bool *visited,bool *cur_visited,bool &ans)
    {
        visited[sv]=true;
        cur_visited[sv]=true;
        for(int i=0;i<(edges[sv].size());i++)
        {
            int adj=edges[sv][i];
            if(cur_visited[adj])
            {
                ans=true;
                return ;
            }else{
                func(edges,adj,visited,cur_visited,ans);
            }
            if(ans)
            {
                return ;
            }
        }
        cur_visited[sv]=false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int> *edges=new vector<int>[n];
        int x,y;
        for(int i=0;i<(a.size());i++)
        {
            x=a[i][0];
            y=a[i][1];
            edges[x].push_back(y);
        }
        bool *visited=new bool[n];
        bool *cur_visited=new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
            cur_visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool ans=false;
                func(edges,i,visited,cur_visited,ans);
                if(ans)
                {
                    vector<int> fin;
                    return fin;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        stack<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(edges,i,visited,ans);
            }
        }
        vector<int> fin;
        while(!ans.empty())
        {
            fin.push_back(ans.top());
            ans.pop();
        }
        reverse(fin.begin(),fin.end());
        return fin;
    }
};
