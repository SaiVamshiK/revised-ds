
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

typedef pair<int,pair<int,int>> pi;
vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    int n=a.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> ans;
    int cnt=0;
    priority_queue<pi> pq;
    set<pair<int,int>> st;
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    st.insert({n-1,n-1});
    while(!pq.empty())
    {
        pi temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        cnt++;
        if(cnt==n)
        {
            return ans;
        }
        int x=temp.second.first,y=temp.second.second;
        // x-1,y
        if((x-1>=0)&&(st.find({x-1,y})==st.end()))
        {
            pq.push({a[x-1]+b[y],{x-1,y}});
            st.insert({x-1,y});
        }
        // x,y-1
        if((y-1>=0)&&(st.find({x,y-1})==st.end()))
        {
            pq.push({a[x]+b[y-1],{x,y-1}});
            st.insert({x,y-1});
        }
    }
    return ans;
}

