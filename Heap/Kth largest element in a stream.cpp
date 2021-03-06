
Given an input stream arr[] of n integers, find the kth largest element for each element in the stream.

Example 1:

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.

class Solution{  
  public:
    vector<int> kthLargest(int k, int a[], int n) {
        vector<int> ans;
        for(int i=0;i<(k-1);i++)
        {
            ans.push_back(-1);
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push(a[i]);
        }
        ans.push_back(pq.top());
        for(int i=k;i<n;i++)
        {
            pq.push(a[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};
