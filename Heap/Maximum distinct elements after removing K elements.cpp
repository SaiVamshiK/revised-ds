
Given an array containing N elements. The task is to find the maximum number of distinct elements after removing K elements from the array.

Example 1:

Input : Arr[] = {5, 7, 5, 5, 1, 2, 2}, K = 3
Output : 4
Explanation:
Remove 2 occurrences of element 5 and 
1 occurrence of element 2.

class Solution{
    public:
    int maxDistinctNum(int a[], int n, int k)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        priority_queue<int> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push(it->second);
        }
        while(!pq.empty()&&(k--))
        {
            int freq=pq.top();
            pq.pop();
            freq--;
            if(freq!=0)
            {
                pq.push(freq);
            }
        }
        return pq.size();
    }
};
