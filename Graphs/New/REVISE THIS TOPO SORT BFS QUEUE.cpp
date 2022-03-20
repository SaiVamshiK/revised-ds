There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        int *in=new int[n];
        for(int i=0;i<n;i++)
        {
            in[i]=0;
        }
        vector<int> *edges=new vector<int>[n];
        int x,y;
        for(int i=0;i<(a.size());i++)
        {
            x=a[i][0];
            y=a[i][1];
            edges[x].push_back(y);
            in[y]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<(edges[x].size());i++)
            {
                int adj=edges[x][i];
                if(in[adj]>0)
                {
                    in[adj]--;
                }
                if(in[adj]==0)
                {
                    q.push(adj);
                }
            }
        }
        return cnt==n;
    }
};



