
Problem Description

Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit 
by selling the tickets to B people.

int Solution::solve(vector<int> &a, int k) {
    int n=a.size();
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }
    int cost=0;
    while(k--)
    {
        int x=pq.top();
        cost+=(pq.top());
        pq.pop();
        x--;
        if(x!=0)
        {
            pq.push(x);
        }
    }
    return cost;
}

