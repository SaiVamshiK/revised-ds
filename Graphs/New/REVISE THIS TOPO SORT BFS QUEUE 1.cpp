
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So 
the correct course order is [0,1].

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
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
        vector<int> ans;
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
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
        if(cnt==n)
        {
            reverse(ans.begin(),ans.end());
            return ans;
        }
        vector<int> fin;
        return fin;
    }
};
