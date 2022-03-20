
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

class Solution {
public:
    void func(vector<bool> &visited,int i,int n,int &cnt)
    {
        if(i==(n+1))
        {
            cnt++;
            return ;
        }
        for(int x=1;x<=n;x++)
        {
            if(!visited[x]&&(((x%i==0))||((i%x==0))))
            {
                visited[x]=true;
                func(visited,i+1,n,cnt);
                visited[x]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n+1,false);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            visited[i]=true;
            func(visited,2,n,cnt);
            visited[i]=false;
        }
        return cnt;
    }
};
