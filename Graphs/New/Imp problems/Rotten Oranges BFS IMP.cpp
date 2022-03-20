
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

typedef pair<int,int> pi;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pi> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==2)
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int answer=0;
        while(!q.empty())
        {
            int sz=q.size();
            int cnt=0;
            for(int z=1;z<=sz;z++)
            {
                pi front_elem=q.front();
                q.pop();
                int r=front_elem.first,c=front_elem.second;
                // r,c+1
                if((c+1<m)&&(!visited[r][c+1])&&(a[r][c+1]==1))
                {
                    q.push({r,c+1});
                    visited[r][c+1]=true;
                    a[r][c+1]=2;
                    cnt++;
                }
                // r+1,c
                if((r+1<n)&&(!visited[r+1][c])&&(a[r+1][c]==1))
                {
                    q.push({r+1,c});
                    visited[r+1][c]=true;
                    a[r+1][c]=2;
                    cnt++;
                }
                // r-1,c
                if((r-1>=0)&&(!visited[r-1][c])&&(a[r-1][c]==1))
                {
                    q.push({r-1,c});
                    visited[r-1][c]=true;
                    a[r-1][c]=2;
                    cnt++;
                }
                // r,c-1
                if((c-1>=0)&&(!visited[r][c-1])&&(a[r][c-1]==1))
                {
                    q.push({r,c-1});
                    visited[r][c-1]=true;
                    a[r][c-1]=2;
                    cnt++;
                }   
            }
            if(cnt!=0)
            {
                answer++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return answer;
    }
};
