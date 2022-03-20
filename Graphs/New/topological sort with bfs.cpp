
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& vec) {
        vector<int> ans;
        if(n==0)
        {
            return ans;
        }
        int **edges=new int*[n];
        for(int i=0;i<n;i++)
        {
            edges[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                edges[i][j]=0;
            }
        }
        for(int i=0;i<(vec.size());i++)
        {
            int x=vec[i][0],y=vec[i][1];
            edges[y][x]=1;
        }
        int *in_degree=new int[n];
        for(int i=0;i<n;i++)
        {
            in_degree[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int cur=i;
            for(int j=0;j<n;j++)
            {
                if(edges[j][cur]==1)
                {
                    in_degree[cur]++;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in_degree[i]==0)
            {
                q.push(i);
            }
        }
        if(q.empty())
        {
            return ans;
        }
        int count=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
            count++;
            for(int i=0;i<n;i++)
            {
                if(edges[x][i]==1)
                {
                    in_degree[i]--;
                    if(in_degree[i]==0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        if(count!=n)
        {
            vector<int> t;
            return t;
        }else{
            return ans;
        }
    }
};














