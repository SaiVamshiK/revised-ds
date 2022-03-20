Given a sorted array, arr[] of N integers, and a value X. Find the K closest elements to X in arr[].
Keep the following points in mind:

If X is present in the array, then it need not be considered.
If there are two elements with the same difference with X, the greater element is given priority.
If sufficient elements are not present on the right side then take elements from left and vice versa.


Example 2:

Input:
N = 5
Arr[] = {1, 2, 3, 6, 10}
K = 3, X = 4
Output: 3 6 2
Explanation: 
First closest element is 3.
There are two elements 2 and 6 for which 
the difference with 4 is same i.e. 2.
So first take greatest number 6 
then the lower number 2.


typedef pair<int,int> pi;
class Compare{
    public:
    bool operator()(pi a,pi b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};
// < => Max Heap
// > => Min Heap
class Solution{   
public:
    vector<int> printKClosest(vector<int> a, int n, int k, int x) {
        priority_queue<pi,vector<pi>,Compare> pq;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            {
                continue;
            }
            pq.push({abs(a[i]-x),a[i]});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};




