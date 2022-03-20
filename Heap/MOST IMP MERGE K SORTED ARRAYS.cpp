
You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.

YT Video Link:
Similar to merge 2 arrays but extended to k arrays by maintaining k pointers.
https://www.youtube.com/watch?v=ptYUCjfNhJY&t=450s

typedef pair<int,pair<int,int>> pi;
vector<int> Solution::solve(vector<vector<int> > &a) {
    int n=a.size(),m=a[0].size();
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push({a[i][0],{i,0}});
    }
    vector<int> ans;
    while(!pq.empty())
    {
        pi temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        int rowNo=temp.second.first;
        int colNo=temp.second.second;
        if(colNo!=(m-1))
        {
            pq.push({a[rowNo][colNo+1],{rowNo,colNo+1}});
        }
    }
    return ans;
}

