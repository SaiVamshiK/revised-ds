

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 103

1 <= C <= N



Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.



Output Format
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:

The returned array must be sorted in non-increasing order.



Example Input
Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


Example Output
Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]
 
 
Sort both arrays array A and array B.

Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B 
which make up the sum. Heap is ordered by the sum.

Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices 
of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first
value i.e sum of both elements.

Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).

Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) 
and (i, j – 1) are not
already present in the max heap. To check this we can use set in C++.

Go back to 4 until K times.

typedef pair<int,pair<int,int>> pi;
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int k) {
    int n=a.size();
    vector<int> ans;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<pi> pq;
    set<pair<int,int>> st;
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    st.insert({n-1,n-1});
    int cnt=0;
    while(!pq.empty())
    {
        pi temp=pq.top();
        pq.pop();
        ans.push_back(temp.first);
        cnt++;
        if(cnt==k)
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

